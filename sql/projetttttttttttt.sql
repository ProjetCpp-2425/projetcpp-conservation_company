CREATE TABLE CLIENTS (
    ID_Client INT PRIMARY KEY,
    Nom VARCHAR(255),
    Adresse TEXT,
    Prenom VARCHAR(255),
    Numero BIGINT,
    Email VARCHAR(255),
    TYPE VARCHAR(255),
    Identifiant_1 INT
);

CREATE TABLE Employee (
    Id_employee INT PRIMARY KEY,
    Identifiant_1 INT
);

CREATE TABLE Produit (
    Reference_Prod INT PRIMARY KEY,
    Etat_Stock VARCHAR(50),
    Quantite_dispo INT,
    Seuil_de_reapprovisionnement INT,
    Date DATE,
    Type_Emballage VARCHAR(255),
    Identifiant_1 INT
);

CREATE TABLE Livraison (
    num_suiv INT PRIMARY KEY,
    transporteur VARCHAR(255),
    date_sortie DATE,
    date_arrivee DATE,
    Identifiant_1 INT
);

-- Relation APPORTER entre Clients et Livraison (1,n - 1,n)
CREATE TABLE Apporter (
    ID_Client INT,
    num_suiv INT,
    PRIMARY KEY (ID_Client, num_suiv),
    FOREIGN KEY (ID_Client) REFERENCES Clients(ID_Client),
    FOREIGN KEY (num_suiv) REFERENCES Livraison(num_suiv)
);

-- Relation CONTENIR entre Livraison et Produit (1,n - 1,n)
CREATE TABLE Contenir (
    num_suiv INT,
    Reference_Prod INT,
    PRIMARY KEY (num_suiv, Reference_Prod),
    FOREIGN KEY (num_suiv) REFERENCES Livraison(num_suiv),
    FOREIGN KEY (Reference_Prod) REFERENCES Produit(Reference_Prod)
);