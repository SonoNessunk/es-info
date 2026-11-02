<?php

function calcolaCassa(float $imponibile, float $percentuale = 4.0): float
{
    return $imponibile * ($percentuale / 100);
}

function calcolaIva(float $totaleParziale, float $aliquotaIva = 22.0): float
{
    return $totaleParziale * ($aliquotaIva / 100);
}

function formattaValuta(float $valore): string
{
    return number_format($valore, 2, ',', '.') . ' €';
}
