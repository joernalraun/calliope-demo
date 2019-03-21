//
// Created by wowa on 13.03.19.
//

#ifndef CALLIOPE_DEMO_CALLIOPESERVICEMASTER_H
#define CALLIOPE_DEMO_CALLIOPESERVICEMASTER_H


//#include "ManagedString.h"
#include "CalliopeRGB.h"
#include "ble/BLE.h"
#include "Interpreter.h"
#include "CalliopeServiceRGB.h"
#include "CalliopeServiceMicrophone.h"
#include "CalliopeServiceLightSensor.h"
#include "BluetoothServiceProgram.h"
#include "BluetoothServiceNotify.h"

// Flags for new implemented Calliope Services
#define CALLIOPE_SERVICE_FLAG_RGB           (uint32_t)0x00000001
#define CALLIOPE_SERVICE_FLAG_MICROPHONE    (uint32_t)0x00000002
#define CALLIOPE_SERVICE_FLAG_BRIGHTNESS    (uint32_t)0x00000004
#define CALLIOPE_SERVICE_FLAG_SPEAKER       (uint32_t)0x00000008

// Flags for already implemented Microbit Services
#define CALLIOPE_SERVICE_FLAG_LED           (uint32_t)0x00000010
#define CALLIOPE_SERVICE_FLAG_TEMPERATURE   (uint32_t)0x00000020
#define CALLIOPE_SERVICE_FLAG_BUTTON        (uint32_t)0x00000040
#define CALLIOPE_SERVICE_FLAG_MAGNETOMETER  (uint32_t)0x00000080

#define CALLIOPE_SERVICE_FLAG_ACCELEROMETER (uint32_t)0x00000100
#define CALLIOPE_SERVICE_FLAG_RES_10        (uint32_t)0x00000200
#define CALLIOPE_SERVICE_FLAG_RES_11        (uint32_t)0x00000400
#define CALLIOPE_SERVICE_FLAG_RES_12        (uint32_t)0x00000800

#define CALLIOPE_SERVICE_FLAG_RES_13        (uint32_t)0x00001000
#define CALLIOPE_SERVICE_FLAG_RES_14        (uint32_t)0x00002000
#define CALLIOPE_SERVICE_FLAG_RES_15        (uint32_t)0x00004000
#define CALLIOPE_SERVICE_FLAG_RES_16        (uint32_t)0x00008000

#define CALLIOPE_SERVICE_FLAG_RES_17        (uint32_t)0x00010000
#define CALLIOPE_SERVICE_FLAG_RES_18        (uint32_t)0x00020000
#define CALLIOPE_SERVICE_FLAG_RES_19        (uint32_t)0x00040000
#define CALLIOPE_SERVICE_FLAG_RES_20        (uint32_t)0x00080000

#define CALLIOPE_SERVICE_FLAG_RES_21        (uint32_t)0x00100000
#define CALLIOPE_SERVICE_FLAG_RES_22        (uint32_t)0x00200000
#define CALLIOPE_SERVICE_FLAG_RES_23        (uint32_t)0x00400000
#define CALLIOPE_SERVICE_FLAG_RES_24        (uint32_t)0x00800000

#define CALLIOPE_SERVICE_FLAG_EVENT         (uint32_t)0x01000000
#define CALLIOPE_SERVICE_FLAG_RES_26        (uint32_t)0x02000000
#define CALLIOPE_SERVICE_FLAG_RES_27        (uint32_t)0x04000000
#define CALLIOPE_SERVICE_FLAG_RES_28        (uint32_t)0x08000000

#define CALLIOPE_SERVICE_FLAG_RES_29        (uint32_t)0x10000000
#define CALLIOPE_SERVICE_FLAG_PROGRAM       (uint32_t)0x20000000
#define CALLIOPE_SERVICE_FLAG_NOTIFY        (uint32_t)0x40000000
#define CALLIOPE_SERVICE_FLAG_RESET         (uint32_t)0x80000000

#define DEBUG_MASTER

#ifdef DEBUG_MASTER
#define LOG(format, ...) uBit.serial.printf(format, ##__VA_ARGS__)
#else
#define LOG(format, ...) ;
#endif




extern const uint8_t  CalliopeMasterServiceUUID[];
extern const uint8_t CalliopeMasterServiceCharacteristicUUID[];

/*!
 * @class BluetoothServiceNotify
 */

class CalliopeServiceMaster
{
public:

    /*!
     * Constructor.
     * Create a representation of BluetoothServiceNotify
     * @param interpreter Reference to an Interpreter instance
     */
    CalliopeServiceMaster(BLEDevice &_ble);

    /*!
     * Callback. Invoked when any of our attributes are read via BLE.
     */
    void onDataRead(GattReadAuthCallbackParams *params);

    /*!
     * Callback. Invoked when any of our attributes are written via BLE.
     */
    void onDataWritten(const GattWriteCallbackParams *params);


    /*!
     *
     * @param requestedStatus
     * @return
     */
    uint32_t updateServices(const uint32_t requestedStatus);

    void setStatus(const uint8_t *status);

    uint8_t getStatus(uint8_t *status);



        /*!
         * Send data via BLE.
         * @param reply
         */
    void send(const uint8_t *reply);

private:
    // all required references to functionality

//    Interpreter *interpreter;
    BLEDevice &ble;

    // all required references to services

    GattAttribute::Handle_t characteristicsHandle;
    uint8_t characteristicBitfield[4];

    uint8_t serviceStatus[4];

    uint8_t statusChanged;
};

#endif //CALLIOPE_DEMO_CALLIOPESERVICEMASTER_H
