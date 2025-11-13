.. _high_duty_adv-sample:

Bluetooth: High Duty Cycle Directed Advertising
###############################################

Overview
********

A simple Bluetooth LE application that demonstrates high duty cycle directed
advertising to a randomly generated target address. The application generates
a random target address at startup and then starts directed advertising using
high duty cycle intervals as defined by the Bluetooth specification for directed
advertising.

This sample is useful for testing WURX (Wake-up receive) functionality with EVK
to EVK communication. See the ``openair/samples/bluetooth/sensor_beacon``
application.

Sample Output
=============

.. code-block:: console

    *** Booting Zephyr OS build v4.2.0-114074-g2c490fe1a553 ***
    *** OpenAir v25.09.0 (PD50) ***
    [00:00:00.004,000] <inf> high_duty_adv: Starting High Duty Cycle Advertising
    [00:00:00.021,000] <inf> bt_hci_core: HCI transport: Atmosic BLE
    [00:00:00.021,000] <inf> bt_hci_core: Identity: A6:B1:AF:3A:EA:65 (public)
    [00:00:00.021,000] <inf> bt_hci_core: HCI: version 6.0 (0x0e) revision 0x0302, manufacturer 0x0a24
    [00:00:00.021,000] <inf> bt_hci_core: LMP: version 6.0 (0x0e) subver 0x0302
    [00:00:00.022,000] <inf> high_duty_adv: Bluetooth initialized
    [00:00:00.022,000] <inf> high_duty_adv: Self BD address: A6:B1:AF:3A:EA:65 (public)
    [00:00:00.023,000] <inf> high_duty_adv: Target BD address: FF:E4:EF:05:6B:DF (random) (randomly generated)
    [00:00:00.026,000] <inf> high_duty_adv: High duty cycle directed advertising started successfully
