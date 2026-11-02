<?php
require_once 'calcoli_fiscali.php';

$descrizioneServizio = "Sviluppo Sito Web E-commerce";
$tariffaOraria = 35.00;
$oreLavorate = 40;
$scontoPromo = 50.00;

$compensoLordo = $tariffaOraria * $oreLavorate;
$imponibile = $compensoLordo - $scontoPromo;
$cassaInps = calcolaCassa($imponibile);
$subtotale = $imponibile + $cassaInps;
$iva = calcolaIva($subtotale);
$totaleDaPagare = $subtotale + $iva;
?>

<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Preventivo</title>
    <style>
        body {
            background-color: #f8f9fa;
            font-family: monospace;
            padding: 20px;
            color: #212529;
        }

        .scontrino {
            background-color: #ffffff;
            border: 1px dashed #ced4da;
            padding: 25px;
            max-width: 500px;
            margin: 0 auto;
            line-height: 1.6;
            border-radius: 5px;
        }

        .title {
            text-align: center;
        }

        .row {
            display: flex;
            justify-content: space-between;
        }

        .separatore-dash {
            border-top: 1px dashed #495057;
            margin: 8px 0;
        }

        .separatore-ugule {
            color: #495057;
            text-align: center;
            margin: 5px 0;
            white-space: nowrap;
            overflow: hidden;
        }
    </style>
</head>

<body>

    <div class="scontrino">
        <div class="separatore-ugule">===============================================================================</div>
        <div class="title">RIEPILOGO PREVENTIVO</div>
        <div class="separatore-ugule">===============================================================================</div>

        <div>Servizio: <?php echo htmlspecialchars($descrizioneServizio, ENT_QUOTES, 'UTF-8'); ?></div>

        <div class="row">
            <span>Compenso (<?php echo $oreLavorate; ?>h &times; <?php echo formattaValuta($tariffaOraria); ?>/h):</span>
            <span><?php echo formattaValuta($compensoLordo); ?></span>
        </div>

        <div class="row">
            <span>Sconto applicato:</span>
            <span>- <?php echo formattaValuta($scontoPromo); ?></span>
        </div>

        <div class="separatore-dash"></div>

        <div class="row">
            <span>Imponibile:</span>
            <span><?php echo formattaValuta($imponibile); ?></span>
        </div>

        <div class="row">
            <span>Rivalsa Cassa INPS (4%):</span>
            <span>+ <?php echo formattaValuta($cassaInps); ?></span>
        </div>

        <div class="separatore-dash"></div>

        <div class="row">
            <span>Subtotale:</span>
            <span><?php echo formattaValuta($subtotale); ?></span>
        </div>

        <div class="row">
            <span>IVA (22%):</span>
            <span>+ <?php echo formattaValuta($iva); ?></span>
        </div>

        <div class="separatore-ugule">===============================================================================</div>

        <div class="row">
            <span>TOTALE FATTURA:</span>
            <span><?php echo formattaValuta($totaleDaPagare); ?></span>
        </div>

        <div class="separatore-ugule">===============================================================================</div>
    </div>

</body>

</html>