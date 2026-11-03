<?php
require_once 'calcoli_spedizione.php';

$prodotti = $_POST['prodotto'];
$valoreMerci = $_POST['valore'];
$pesoTotaleKg = $_POST['peso'];

$costoSpedizione = calcolaSpedizione($pesoTotaleKg);
$assicurazione = calcolaAssicurazione($valoreMerci);
$imponibileServizi = $costoSpedizione + $assicurazione;
$ivaSpedizione = calcolaIvaSpedizione($imponibileServizi);
$totale = $valoreMerci + $imponibileServizi + $ivaSpedizione;
?>

<!DOCTYPE html>
<html lang="it">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Riepilogo Ordine & Spedizione</title>
    <style>
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

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
        <div class="title">RIEPILOGO ORDINE & SPEDIZIONE</div>
        <div class="separatore-ugule">===============================================================================</div>

        <div class="row">
            <span>Articoli:</span>
            <span><?php echo $prodotti; ?></span>
        </div>

        <div class="row">
            <span>Valore Merci:</span>
            <span><?php echo formattaEuro($valoreMerci); ?></span>
        </div>

        <div class="row">
            <span>Peso Totale (>10Kg, +5€):</span>
            <span><?php echo number_format($pesoTotaleKg, 1, ',', '.'); ?> Kg</span>
        </div>

        <div class="separatore-dash"></div>

        <div class="row">
            <span>Costo Spedizione: </span>
            <span><?php echo formattaEuro($costoSpedizione); ?></span>
        </div>

        <div class="row">
            <span>Assicurazione (1,5%): </span>
            <span><?php echo formattaEuro($assicurazione); ?></span>
        </div>

        <div class="separatore-dash"></div>

        <div class="row">
            <span>Imponibile Servizi: </span>
            <span><?php echo formattaEuro($imponibileServizi); ?></span>
        </div>

        <div class="row">
            <span>IVA Spedizione (22%): </span>
            <span><?php echo formattaEuro($ivaSpedizione); ?></span>
        </div>

        <div class="separatore-ugule">===============================================================================</div>
        <div class="row totale">
            <span>TOTALE COMPLESSIVO: </span>
            <span><?php echo formattaEuro($totale); ?></span>
        </div>
        <div class="separatore-ugule">===============================================================================</div>
    </div>

</body>

</html>