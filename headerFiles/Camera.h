#include <Eigen/Dense>

class Camera
{
private:
    Eigen::Vector3f eye;
    Eigen::Vector3f lookAt;
    Eigen::Vector3f orientation;
    float translationStep = 0.1;
    float rotationAngle = 0.0174532925199433;
public:
    // Constructor for camera object
    Camera(Eigen::Vector3f eye, Eigen::Vector3f lookAt, Eigen::Vector3f orientation)
    {
        this->eye = eye;
        this->lookAt = lookAt;
        this->orientation = orientation;
    }
    // Destructor for camera object
    ~Camera() { }
    
    // Function to set up all camera variables
    void setup()
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, 16 / 9.0, 0.001, 200);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(eye.x(), eye.y(), eye.z(), lookAt.x(), lookAt.y(), lookAt.z(), orientation.x(), orientation.y(), orientation.z());
    }

    // Rotation Functions
    void rotateRight(float scale = 1)
    {
        float theta = rotationAngle * scale / 2;
        Eigen::Quaternionf rotAxis(theta, orientation.x(), orientation.y(), orientation.z());
        rotAxis.normalize();
        Eigen::Quaternionf VectorToRotate;
        VectorToRotate.w() = 0;
        VectorToRotate.vec() = eye - lookAt;
        lookAt = eye + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
        Eigen::Quaternionf rotAxis2(theta, orientation.x(), orientation.y(), orientation.z());
        rotAxis2.normalize();
        Eigen::Quaternionf VectorToRotate2;
        VectorToRotate2.w() = 0;
        VectorToRotate2.vec() = eye - lookAt;
        lookAt = eye + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
    }

    void rotateLeft(float scale = 1)
    {
        float theta = - rotationAngle * scale / 2;
        Eigen::Quaternionf rotAxis(theta, orientation.x(), orientation.y(), orientation.z());
        rotAxis.normalize();
        Eigen::Quaternionf VectorToRotate;
        VectorToRotate.w() = 0;
        VectorToRotate.vec() = eye - lookAt;
        lookAt = eye + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
        Eigen::Quaternionf rotAxis2(theta, orientation.x(), orientation.y(), orientation.z());
        rotAxis2.normalize();
        Eigen::Quaternionf VectorToRotate2;
        VectorToRotate2.w() = 0;
        VectorToRotate2.vec() = eye - lookAt;
        lookAt = eye + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
    }

    void rotateUp(float scale = 1)
    {
        float theta = -rotationAngle * scale / 2;
        Eigen::Vector3f newX = orientation.cross(eye - lookAt);
        Eigen::Quaternionf rotAxis(theta, newX.x(), newX.y(), newX.z());
        rotAxis.normalize();
        Eigen::Quaternionf VectorToRotate;
        VectorToRotate.w() = 0;
        VectorToRotate.vec() = eye - lookAt;
        lookAt = eye + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
        Eigen::Quaternionf rotAxis2(theta, newX.x(), newX.y(), newX.z());
        rotAxis2.normalize();
        Eigen::Quaternionf VectorToRotate2;
        VectorToRotate2.w() = 0;
        VectorToRotate2.vec() = eye - lookAt;
        lookAt = eye + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
    }

    void rotateDown(float scale = 1)
    {
        float theta = rotationAngle * scale / 2;
        Eigen::Vector3f newX = orientation.cross(eye - lookAt);
        Eigen::Quaternionf rotAxis(theta, newX.x(), newX.y(), newX.z());
        rotAxis.normalize();
        Eigen::Quaternionf VectorToRotate;
        VectorToRotate.w() = 0;
        VectorToRotate.vec() = eye - lookAt;
        lookAt = eye + (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
        Eigen::Quaternionf rotAxis2(theta, newX.x(), newX.y(), newX.z());
        rotAxis2.normalize();
        Eigen::Quaternionf VectorToRotate2;
        VectorToRotate2.w() = 0;
        VectorToRotate2.vec() = eye - lookAt;
        lookAt = eye + (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
    }

    void tiltRight(float scale = 1)
    {
        float theta = rotationAngle * scale / 2;
        Eigen::Vector3f newZ = eye - lookAt;
        Eigen::Quaternionf rotAxis(theta, newZ.x(), newZ.y(), newZ.z());
        rotAxis.normalize();
        Eigen::Quaternionf VectorToRotate;
        VectorToRotate.w() = 0;
        VectorToRotate.vec() = orientation;
        orientation = (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
        Eigen::Quaternionf rotAxis2(theta, newZ.x(), newZ.y(), newZ.z());
        rotAxis2.normalize();
        Eigen::Quaternionf VectorToRotate2;
        VectorToRotate2.w() = 0;
        VectorToRotate2.vec() = orientation;
        orientation = (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
    }

    void tiltLeft(float scale = 1)
    {
        float theta = -rotationAngle * scale / 2;
        Eigen::Vector3f newZ = eye - lookAt;
        Eigen::Quaternionf rotAxis(theta, newZ.x(), newZ.y(), newZ.z());
        rotAxis.normalize();
        Eigen::Quaternionf VectorToRotate;
        VectorToRotate.w() = 0;
        VectorToRotate.vec() = orientation;
        orientation = (rotAxis * VectorToRotate * rotAxis.inverse()).vec();
        Eigen::Quaternionf rotAxis2(theta, newZ.x(), newZ.y(), newZ.z());
        rotAxis2.normalize();
        Eigen::Quaternionf VectorToRotate2;
        VectorToRotate2.w() = 0;
        VectorToRotate2.vec() = orientation;
        orientation = (rotAxis2 * VectorToRotate2 * rotAxis2.inverse()).vec();
    }

    // Translation Functions
    void translateForward(float scale = 1)
    {
        float step = translationStep * scale;
        Eigen::Vector3f direction = (lookAt - eye).normalized();
        direction *= step;
        direction.y() = 0;
        eye += direction;
        lookAt += direction;
    }

    void translateBackward(float scale = 1)
    {
        float step = translationStep * scale;
        Eigen::Vector3f direction = (lookAt - eye).normalized();
        direction *= step;
        direction.y() = 0;
        eye -= direction;
        lookAt -= direction;
    }

    void translateLeft(float scale = 1)
    {
        float step = translationStep * scale;
        Eigen::Vector3f direction = (orientation.cross(lookAt - eye)).normalized();
        direction *= step;
        direction.y() = 0;
        eye += direction;
        lookAt += direction;
    }

    void translateRight(float scale = 1)
    {
        float step = translationStep * scale;
        Eigen::Vector3f direction = (orientation.cross(lookAt - eye)).normalized();
        direction *= step;
        direction.y() = 0;
        eye -= direction;
        lookAt -= direction;
    }

    void translateUp(float scale = 1)
    {
        float step = translationStep * scale;
        Eigen::Vector3f direction = (orientation).normalized();
        direction *= step;
        direction.x() = 0;
        direction.z() = 0;
        eye += direction;
        lookAt += direction;
    }

    void translateDown(float scale = 1)
    {
        float step = translationStep * scale;
        Eigen::Vector3f direction = (orientation).normalized();
        direction *= step;
        direction.x() = 0;
        direction.z() = 0;
        eye -= direction;
        lookAt -= direction;
    }

    // Reset all variables to base values if needed
    void reset()
    {

    }
};