<?php
function calcolaSpedizione(float $pesoKg, float $tariffaAlKg = 2.5): float
{
    $costoBase = $pesoKg * $tariffaAlKg;
    if ($pesoKg > 10.0) {
        $costoBase += 5.00;
    }
    return $costoBase;
}

function calcolaAssicurazione(float $valoreMerci, float $percentuale = 1.5): float
{
    return $valoreMerci * ($percentuale / 100);
}

function calcolaIvaSpedizione(float $importoNetto, float $aliquota = 22.0): float
{
    return $importoNetto * ($aliquota / 100);
}

function formattaEuro(float $importo): string
{
    return number_format($importo, 2, ',', '.') . ' €';
}
