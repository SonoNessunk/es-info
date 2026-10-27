<?php
$carrello = [
    ["nome" => "Mouse Wireless", "prezzo" => 15.50, "quantita" => 2],
    ["nome" => "Tastiera Meccanica", "prezzo" => 45.00, "quantita" => 1],
    ["nome" => "Cuffie Gaming", "prezzo" => 29.99, "quantita" => 1]
];

$totaleGenerale = 0;
?>

<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body {
            font-family: Helvetica;
            background-color: #f4f6f8;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            margin: 0;
        }

        .cart-container {
            background-color: #ffffff;
            border-radius: 12px;
            box-shadow: 0 8px 24px rgba(0, 0, 0, 0.08);
            padding: 28px;
            width: 100%;
            max-width: 650px;
        }

        h1 {
            margin-top: 0;
            color: #1e293b;
            font-size: 1.5rem;
            border-bottom: 3px solid #2563eb;
            padding-bottom: 10px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }

        th, td {
            text-align: left;
            padding: 12px 14px;
            border-bottom: 1px solid #e2e8f0;
        }

        th {
            background-color: #f8fafc;
            color: #64748b;
            font-size: 0.85rem;
            text-transform: uppercase;
            letter-spacing: 0.05em;
        }

        .text-center {
            text-align: center;
        }

        .text-right {
            text-align: right;
        }
    </style>
</head>
<body>

    <div class="cart-container">
        <h1>Riepilogo Carrello</h1>

        <table>
            <tr>
                <th>Prodotto</th>
                <th class="text-center">Quantità</th>
                <th class="text-right">Prezzo Unitario</th>
                <th class="text-right">Subtotale</th>
            </tr>
    
            <?php 
            foreach ($carrello as $prodotto) {
                $subtotale = $prodotto["prezzo"] * $prodotto["quantita"];
                
                $totaleGenerale += $subtotale;
            ?>
                <tr>
                    <td><?php echo htmlspecialchars($prodotto["nome"]); ?></td>
                    <td class="text-center"><?php echo $prodotto["quantita"]; ?></td>
                    <td class="text-right">€ <?php echo number_format($prodotto["prezzo"], 2, ',', '.'); ?></td>
                    <td class="text-right">€ <?php echo number_format($subtotale, 2, ',', '.'); ?></td>
                </tr>
            <?php 
            } 
            ?>
    
            <tr class="total-row">
                <td colspan="3" class="text-right">Totale Ordine:</td>
                <td class="text-right">€ <?php echo number_format($totaleGenerale, 2, ',', '.'); ?></td>
            </tr>
        </table>
    </div>

</body>
</html>