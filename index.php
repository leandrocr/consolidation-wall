<?php

error_reporting(0);

require_once __DIR__.'/vendor/autoload.php';

$app = new Silex\Application();

$app->get('/consolidation-wall/slot/{slot}', function ($slot) use ($app) {
    $matrixConsolidation = [
        'A3' => 13,
        'A2' => 12,
        'A1' => 11,
        'B3' => 10,
        'B2' => 9,
        'B1' => 8
    ];

    $serial = new PhpSerial;

    $serial->deviceSet("/dev/cu.usbmodem1421");
    $serial->confBaudRate(9600);

    $serial->deviceOpen();
    sleep(1);

    $serial->sendMessage($matrixConsolidation[strtoupper($slot)]);

    return "{\"slot\": \"$slot\", \"status\": \"success\"}";

});

$app->run();
