<?php

$nome = "Maxim Tatar";
$ruolo = "Studente";
$annoNascita = 2008;
$annoCorrente = 2026;
$citta = "Solnečnogorsk";

$eta = $annoCorrente - $annoNascita;
?>

<!doctype html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>

        <style>
            body {
                font-family: Helvetica;
                background-color: #eef2f5;
                display: flex;
                justify-content: center;
                align-items: center;
                min-height: 100vh;
                margin: 0;
            }

            .card {
                background-color: #ffffff;
                padding: 28px 32px;
                border-radius: 12px;
                box-shadow: 0 5px 10px rgba(0, 0, 0, 0.20);
                width: 100%;
                max-width: 360px;
            }

            .card h1 {
                font-size: 1.8rem;
                color: #1e293b;
                margin: 0 0 18px 0;
                text-align: center;
            }

            .card p {
                font-size: 1.2rem;
                color: #64748b;
                margin: 12px 0;
                display: flex;
                justify-content: space-between;
                border-bottom: 1px solid #f1f5f9;
                padding-bottom: 8px;
            }

            .card strong {
                color: #2563eb;
                font-weight: 600;
            }
        </style>
    </head>
    <body>
        <div class="card">
            <h1>Benvenuto, <?php echo htmlspecialchars($nome)?>!</h1>
            <p>
                Ruolo: <strong><?php echo htmlspecialchars($ruolo)?></strong>
            </p>
            <p>
                Età: <strong><?php echo htmlspecialchars($eta)?></strong>
            </p>
            <p>
                Città: <strong><?php echo htmlspecialchars($citta)?></strong>
            </p>
        </div>
    </body>
</html>
