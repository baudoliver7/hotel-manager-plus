-- MySQL dump 10.13  Distrib 5.5.16, for Win32 (x86)
--
-- Host: localhost    Database: gestion_clientele
-- ------------------------------------------------------
-- Server version	5.5.16-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `actualiser`
--

DROP TABLE IF EXISTS `actualiser`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `actualiser` (
  `TableName` varchar(20) NOT NULL,
  `Actualiser` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`TableName`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `actualiser`
--

LOCK TABLES `actualiser` WRITE;
/*!40000 ALTER TABLE `actualiser` DISABLE KEYS */;
INSERT INTO `actualiser` VALUES ('agent',0),('chambre',0),('operations_comptable',0);
/*!40000 ALTER TABLE `actualiser` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `agent`
--

DROP TABLE IF EXISTS `agent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `agent` (
  `MatriculeRecepteur` varchar(50) NOT NULL,
  `Nom` varchar(15) NOT NULL,
  `Prenoms` varchar(30) NOT NULL,
  `SexePrecis` varchar(5) NOT NULL,
  `Login` varchar(15) DEFAULT NULL,
  `Password` varchar(20) DEFAULT NULL,
  `Residence` varchar(25) NOT NULL,
  `NumeroCel` varchar(15) DEFAULT NULL,
  `NumeroTel` varchar(15) DEFAULT NULL,
  `Email` varchar(25) DEFAULT NULL,
  `BoitePostale` varchar(25) DEFAULT NULL,
  `Statut` varchar(10) NOT NULL,
  `idService` int(11) NOT NULL,
  `DateInscription` datetime NOT NULL,
  `DateActivation` datetime DEFAULT NULL,
  `Connecte` tinyint(1) NOT NULL DEFAULT '0',
  `EtatFinConnection` tinyint(1) NOT NULL DEFAULT '1',
  `codeDeSortie` int(11) NOT NULL DEFAULT '0',
  `Activites` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`MatriculeRecepteur`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `agent`
--

LOCK TABLES `agent` WRITE;
/*!40000 ALTER TABLE `agent` DISABLE KEYS */;
INSERT INTO `agent` VALUES ('ADMIN','ADMINISTRATEUR','administrateur','M.','admini','admini','Abidjan','00-00-00-00',NULL,NULL,NULL,'Actif',1,'2011-12-14 16:08:05','2011-12-22 16:08:16',0,0,0,0);
/*!40000 ALTER TABLE `agent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `annuler_occup`
--

DROP TABLE IF EXISTS `annuler_occup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `annuler_occup` (
  `NumAnnulerOccup` int(11) NOT NULL AUTO_INCREMENT,
  `NumOccupation` int(11) NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  `CodeClient` int(11) NOT NULL,
  `Date` datetime NOT NULL,
  PRIMARY KEY (`NumAnnulerOccup`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `annuler_occup`
--

LOCK TABLES `annuler_occup` WRITE;
/*!40000 ALTER TABLE `annuler_occup` DISABLE KEYS */;
/*!40000 ALTER TABLE `annuler_occup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `annuler_reserv`
--

DROP TABLE IF EXISTS `annuler_reserv`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `annuler_reserv` (
  `NumAnnuler` int(11) NOT NULL AUTO_INCREMENT,
  `NumReservation` int(11) NOT NULL,
  `identiteCh` varchar(30) NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  `Date` datetime NOT NULL,
  PRIMARY KEY (`NumAnnuler`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `annuler_reserv`
--

LOCK TABLES `annuler_reserv` WRITE;
/*!40000 ALTER TABLE `annuler_reserv` DISABLE KEYS */;
/*!40000 ALTER TABLE `annuler_reserv` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `categorie_menu`
--

DROP TABLE IF EXISTS `categorie_menu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `categorie_menu` (
  `IdCatMenu` int(11) NOT NULL AUTO_INCREMENT,
  `Libelle` varchar(50) NOT NULL,
  `IdTypeCatMenu` int(11) NOT NULL,
  `Supprimee` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdCatMenu`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `categorie_menu`
--

LOCK TABLES `categorie_menu` WRITE;
/*!40000 ALTER TABLE `categorie_menu` DISABLE KEYS */;
/*!40000 ALTER TABLE `categorie_menu` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chambre`
--

DROP TABLE IF EXISTS `chambre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chambre` (
  `IdentiteCh` varchar(30) NOT NULL,
  `HS` tinyint(1) NOT NULL DEFAULT '0',
  `occupee` tinyint(1) NOT NULL DEFAULT '0',
  `idTypeChambre` int(11) NOT NULL,
  `IdEtage` int(11) NOT NULL DEFAULT '1',
  PRIMARY KEY (`IdentiteCh`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chambre`
--

LOCK TABLES `chambre` WRITE;
/*!40000 ALTER TABLE `chambre` DISABLE KEYS */;
/*!40000 ALTER TABLE `chambre` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `chambres_reservees`
--

DROP TABLE IF EXISTS `chambres_reservees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `chambres_reservees` (
  `idChambreReservee` int(11) NOT NULL AUTO_INCREMENT,
  `identiteCh` varchar(30) NOT NULL,
  `Cout` int(11) NOT NULL DEFAULT '0',
  `Avance` int(11) NOT NULL DEFAULT '0',
  `NumReservation` int(11) NOT NULL,
  `Terminee` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`idChambreReservee`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `chambres_reservees`
--

LOCK TABLES `chambres_reservees` WRITE;
/*!40000 ALTER TABLE `chambres_reservees` DISABLE KEYS */;
/*!40000 ALTER TABLE `chambres_reservees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `client`
--

DROP TABLE IF EXISTS `client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `client` (
  `CodeClient` int(11) NOT NULL AUTO_INCREMENT,
  `Nom` varchar(20) DEFAULT NULL,
  `Prenoms` varchar(50) DEFAULT NULL,
  `Homme` tinyint(1) NOT NULL DEFAULT '1',
  `DateDeNaissance` date DEFAULT NULL,
  `LieuDeNaissance` varchar(160) DEFAULT NULL,
  `Pere` varchar(160) DEFAULT NULL,
  `Mere` varchar(160) DEFAULT NULL,
  `Profession` varchar(160) DEFAULT NULL,
  `DomicileHabituel` varchar(160) DEFAULT NULL,
  `Nationalite` varchar(70) DEFAULT NULL,
  `NumeroCel` varchar(50) DEFAULT NULL,
  `NumeroTel` varchar(50) DEFAULT NULL,
  `Email` varchar(50) DEFAULT NULL,
  `BoitePostale` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`CodeClient`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `client`
--

LOCK TABLES `client` WRITE;
/*!40000 ALTER TABLE `client` DISABLE KEYS */;
/*!40000 ALTER TABLE `client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `clotures_service`
--

DROP TABLE IF EXISTS `clotures_service`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `clotures_service` (
  `IdClotureService` int(11) NOT NULL AUTO_INCREMENT,
  `Date` date NOT NULL,
  `DepotSurCompteClient` int(11) NOT NULL DEFAULT '0',
  `MontantEncaisse` int(11) NOT NULL DEFAULT '0',
  `MontantRetire` int(11) NOT NULL DEFAULT '0',
  `MontantRestant` int(11) NOT NULL DEFAULT '0',
  `ReglementEspece` int(11) NOT NULL DEFAULT '0',
  `ReglementCheque` int(11) NOT NULL DEFAULT '0',
  `ReglementCarteDeCredit` int(11) NOT NULL DEFAULT '0',
  `ReglementCompteClient` int(11) NOT NULL DEFAULT '0',
  `MatriculeAgent` varchar(50) NOT NULL,
  `Depouille` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdClotureService`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clotures_service`
--

LOCK TABLES `clotures_service` WRITE;
/*!40000 ALTER TABLE `clotures_service` DISABLE KEYS */;
/*!40000 ALTER TABLE `clotures_service` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `comptes_client`
--

DROP TABLE IF EXISTS `comptes_client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `comptes_client` (
  `IdCompteClient` int(11) NOT NULL AUTO_INCREMENT,
  `Libelle` varchar(50) NOT NULL,
  `CodeClient` int(11) NOT NULL,
  `Solde` int(11) NOT NULL,
  PRIMARY KEY (`IdCompteClient`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comptes_client`
--

LOCK TABLES `comptes_client` WRITE;
/*!40000 ALTER TABLE `comptes_client` DISABLE KEYS */;
/*!40000 ALTER TABLE `comptes_client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `config_service_compta`
--

DROP TABLE IF EXISTS `config_service_compta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `config_service_compta` (
  `Id_csc` int(11) NOT NULL,
  `Action` varchar(50) NOT NULL,
  `compteAssocie` int(11) NOT NULL DEFAULT '0',
  `Id_se` int(11) NOT NULL,
  PRIMARY KEY (`Id_csc`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `config_service_compta`
--

LOCK TABLES `config_service_compta` WRITE;
/*!40000 ALTER TABLE `config_service_compta` DISABLE KEYS */;
INSERT INTO `config_service_compta` VALUES (1,'R√®glement en esp√®ce',57,3),(2,'R√®glement par ch√®que',0,0),(3,'Cr√©dit client√®le',4111,3),(4,'Location de chambre',7073,3),(5,'Avance sur location',167,3),(6,'Vente de nourriture',0,4),(7,'TVA d√©ductible',4441,2),(8,'TVA collect√©e',4432,2),(9,'Penalit√© sur retard √† la sortie',84,3),(10,'Taxe touristique',4422,2),(11,'Vente de boisson',0,4);
/*!40000 ALTER TABLE `config_service_compta` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `conso_resto`
--

DROP TABLE IF EXISTS `conso_resto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `conso_resto` (
  `IdConsoResto` int(11) NOT NULL AUTO_INCREMENT,
  `IdMenu` int(11) NOT NULL,
  `NbMenu` int(11) NOT NULL,
  `CoutTotal` int(11) NOT NULL,
  `IdRepasCResto` int(11) NOT NULL,
  PRIMARY KEY (`IdConsoResto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conso_resto`
--

LOCK TABLES `conso_resto` WRITE;
/*!40000 ALTER TABLE `conso_resto` DISABLE KEYS */;
/*!40000 ALTER TABLE `conso_resto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `effectuer_reserv`
--

DROP TABLE IF EXISTS `effectuer_reserv`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `effectuer_reserv` (
  `NumEffectuer` int(11) NOT NULL AUTO_INCREMENT,
  `NumReservation` int(11) NOT NULL,
  `identiteCh` varchar(30) NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  `Date` datetime NOT NULL,
  PRIMARY KEY (`NumEffectuer`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `effectuer_reserv`
--

LOCK TABLES `effectuer_reserv` WRITE;
/*!40000 ALTER TABLE `effectuer_reserv` DISABLE KEYS */;
/*!40000 ALTER TABLE `effectuer_reserv` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `emettre_reserv`
--

DROP TABLE IF EXISTS `emettre_reserv`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `emettre_reserv` (
  `NumEmettre` int(11) NOT NULL AUTO_INCREMENT,
  `NumReservation` int(11) NOT NULL,
  `identiteCh` varchar(30) NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  `Date` datetime NOT NULL,
  PRIMARY KEY (`NumEmettre`),
  KEY `NumReservation` (`NumReservation`),
  KEY `MatriculeRecepteur` (`MatriculeRecepteur`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `emettre_reserv`
--

LOCK TABLES `emettre_reserv` WRITE;
/*!40000 ALTER TABLE `emettre_reserv` DISABLE KEYS */;
/*!40000 ALTER TABLE `emettre_reserv` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `etage`
--

DROP TABLE IF EXISTS `etage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `etage` (
  `IdEtage` int(11) NOT NULL AUTO_INCREMENT,
  `Niveau` varchar(20) NOT NULL,
  PRIMARY KEY (`IdEtage`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `etage`
--

LOCK TABLES `etage` WRITE;
/*!40000 ALTER TABLE `etage` DISABLE KEYS */;
INSERT INTO `etage` VALUES (1,'R-C'),(2,'Etage 1'),(3,'Etage 2'),(4,'Etage 3'),(5,'Etage 4'),(6,'Etage 5'),(7,'Etage 6'),(8,'Etage 7'),(9,'Etage 8'),(10,'Etage 9'),(11,'Etage 10'),(12,'Etage 11'),(13,'Etage 12');
/*!40000 ALTER TABLE `etage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `facture_initial`
--

DROP TABLE IF EXISTS `facture_initial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `facture_initial` (
  `idFactureInitial` int(11) NOT NULL,
  `idService` int(11) NOT NULL,
  `Type` varchar(50) NOT NULL,
  `Initial` varchar(15) NOT NULL,
  `Numero` int(11) NOT NULL,
  PRIMARY KEY (`idFactureInitial`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `facture_initial`
--

LOCK TABLES `facture_initial` WRITE;
/*!40000 ALTER TABLE `facture_initial` DISABLE KEYS */;
INSERT INTO `facture_initial` VALUES (1,3,'Facture de location','FREC',0),(2,4,'Facture de restaurant','FRES',0),(3,4,'Facture de bar','FBAR',0);
/*!40000 ALTER TABLE `facture_initial` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `groupe`
--

DROP TABLE IF EXISTS `groupe`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `groupe` (
  `IdGroupe` int(11) NOT NULL AUTO_INCREMENT,
  `Libelle` varchar(50) NOT NULL,
  `IdResponsable` int(11) NOT NULL,
  `NbPersonnesEnreg` int(11) NOT NULL DEFAULT '1',
  `Avance` int(11) NOT NULL DEFAULT '0',
  `FraisLocation` int(11) NOT NULL DEFAULT '0',
  `FraisLocationPayee` int(11) NOT NULL DEFAULT '0',
  `FraisSup` int(11) NOT NULL DEFAULT '0',
  `FraisSupPayee` int(11) NOT NULL DEFAULT '0',
  `DateDemande` datetime NOT NULL,
  `DateOccupation` datetime NOT NULL,
  `DureeOccupation` int(11) NOT NULL,
  `Provenance` varchar(50) DEFAULT NULL,
  `MatriculeAgent` varchar(50) NOT NULL,
  `Terminee` tinyint(1) NOT NULL DEFAULT '0',
  `Facture` varchar(50) NOT NULL DEFAULT '',
  `NumeroTel` varchar(50) DEFAULT '',
  `NumeroCel` varchar(50) DEFAULT '',
  `Email` varchar(50) DEFAULT '',
  `BoitePostale` varchar(50) DEFAULT '',
  `IdProfile` int(11) NOT NULL DEFAULT '0',
  `NbPersonnesPrevu` int(11) NOT NULL DEFAULT '1',
  `IdTypeDeChambreMaj` int(11) NOT NULL DEFAULT '0',
  `AvanceActu` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdGroupe`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `groupe`
--

LOCK TABLES `groupe` WRITE;
/*!40000 ALTER TABLE `groupe` DISABLE KEYS */;
/*!40000 ALTER TABLE `groupe` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `groupe_liaison`
--

DROP TABLE IF EXISTS `groupe_liaison`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `groupe_liaison` (
  `IdGroupeLiaison` int(11) NOT NULL AUTO_INCREMENT,
  `IdGroupe` int(11) NOT NULL,
  `CodeClient` int(11) NOT NULL,
  PRIMARY KEY (`IdGroupeLiaison`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `groupe_liaison`
--

LOCK TABLES `groupe_liaison` WRITE;
/*!40000 ALTER TABLE `groupe_liaison` DISABLE KEYS */;
/*!40000 ALTER TABLE `groupe_liaison` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `heure_bd`
--

DROP TABLE IF EXISTS `heure_bd`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `heure_bd` (
  `NumHeure` int(11) NOT NULL AUTO_INCREMENT,
  `HeureFinOccupation` time NOT NULL,
  `TempsDeTol` int(11) NOT NULL,
  `TempsLocAnnulation` int(11) NOT NULL,
  `LastHourSys` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `DebutActivation` datetime NOT NULL,
  `DureeActivation` int(11) NOT NULL,
  `DureeRestante` int(11) NOT NULL,
  `DureeTolerance` int(11) NOT NULL,
  `Enregistree` tinyint(1) NOT NULL DEFAULT '0',
  `ValeurModifiee` int(11) NOT NULL DEFAULT '0',
  `NumeroInstallation` bigint(20) NOT NULL,
  `DebutActivite` datetime NOT NULL,
  PRIMARY KEY (`NumHeure`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `heure_bd`
--

LOCK TABLES `heure_bd` WRITE;
/*!40000 ALTER TABLE `heure_bd` DISABLE KEYS */;
INSERT INTO `heure_bd` VALUES (1,'12:00:00',15,15,'2013-10-28 10:22:51','2013-10-16 10:26:03',0,0,0,1,0,0,'2013-10-16 10:26:03');
/*!40000 ALTER TABLE `heure_bd` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `heures_activites`
--

DROP TABLE IF EXISTS `heures_activites`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `heures_activites` (
  `NumService` int(11) NOT NULL AUTO_INCREMENT,
  `DateDebut` datetime NOT NULL,
  `DateFin` datetime NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  PRIMARY KEY (`NumService`),
  KEY `MatriculeRecepteur` (`MatriculeRecepteur`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `heures_activites`
--

LOCK TABLES `heures_activites` WRITE;
/*!40000 ALTER TABLE `heures_activites` DISABLE KEYS */;
/*!40000 ALTER TABLE `heures_activites` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `infos_hotel`
--

DROP TABLE IF EXISTS `infos_hotel`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `infos_hotel` (
  `idInfosHotel` int(11) NOT NULL AUTO_INCREMENT,
  `Nom` varchar(50) NOT NULL,
  `SituationGeo` varchar(100) NOT NULL,
  `NumeroTel` varchar(50) NOT NULL,
  `NumeroCel` varchar(50) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `BoitePostale` varchar(100) NOT NULL,
  `SiteWeb` varchar(50) NOT NULL,
  `Logo` longblob NOT NULL,
  `Ville` varchar(50) NOT NULL,
  `NumRecu` int(11) NOT NULL,
  PRIMARY KEY (`idInfosHotel`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `infos_hotel`
--

LOCK TABLES `infos_hotel` WRITE;
/*!40000 ALTER TABLE `infos_hotel` DISABLE KEYS */;
INSERT INTO `infos_hotel` VALUES (1,'HOTEL MANAGER','Marcory Pharmacie Tiacoh','24-65-67-78 / 34-34-65-75','','','01 BP 1909 Abidjan 01','www.hotelmanager.ci','âPNG\r\n\Z\n\0\0\0\rIHDR\0\0\0P\0\0\0<\0\0\0Ò\'=å\0\0\0	pHYs\0\0\0\0“›~¸\0\0+IDATxúÌõ{tT’Ω«?Á53…$ôdÚêbÖ¿\ràV%P®’‚XXjYıAo±¬mk*©K¥ÌΩ|°ÿ\nmEÔUg∏¥ ¯ ÷(Îä 8ÖÑ\0ìêÁdfŒ˘›?ŒÃ@DΩ]íÑv›|ì≥ŒôŸ˚úΩﬂ|{ˇˆÔÏ@?˙—è~¸ˇÖr∂;p*él[˜~d˚ãc÷◊§$\'áÆr¨5Ã§ÍJ“ßﬁq±#{¿ªgªèü«Y\'0¯ÿ˜d˘+ªp:Ü¶‚0TtU≈–TE¡–UTEAUNv˜˚◊M@ù∞¨˜Œ\"Å˜]7Néµv‚44ú∫ÜC◊–5áÆ¢©\nö™b$Æ%N¢¢((\nà¿7œ»Ä9+œ*ë}ﬁ¯ª˜}WVn˙ß°„2l‚ú∫äÆŸá?TU±øSm‰©qBf‹ÚÉ}⁄˘æ°}mÙ1ÅﬂW.©Nùán´ŒP14\ró°°käÌ∫∫ÜÆ⁄DÈ™M™¶⁄™≥âT–T8©DA(À˜0ˆŒÁ˚\\j_5teı`—5{<Sl˚Qí$\"`I¸:~è$~DN{^\\Ñ®*¥vFÿUwú?‹6˘ÙäΩå>!p »b9ÈÜ›Àƒ%`âƒ	µIMÍv\Z§:\rD¿¥Ï2Ä√≠&Ÿó›∆˛Üf]Ìs{]Úó+ítóAäC«Â–qË*N]√àüì„ûÆ&]÷àª≠™*\\\\YDnÜO™wN\ZÊâNÍéµq∏©çœé∑sh?{Ê]¶è¬∑FïíëÍ Õip≈/◊ıâ;˜™á‰gàväÏN™ä§í,âÒk”bñÖ)¬•√ä(ÕMß(œÉ˚Ç2ò2Ç÷)Ás§¿Cùßä›áBiÈ\0`∆èÔÁhK\'\0\':\"|˙⁄ >QbØ∏sÁŒÀIOIJ¸‘1.Aîô Ô∑Lîªù:Yi.<È.§ÿQRy„çl∆]Ωåô?Z»Ωœo„≥Ô!0c∆LÇç-¥á£\0ºæfuoô÷\rΩ&Û Yíë‚¿Ì‘Ìê≈aá,]≈°%f‡ì.õYÏ8PePN\ZìG¬rË∏Ú2», ‚@{ò“qãô=˚R¶è+£nÔqnˇÕü∏¢z0˛ »§Éò:≤ÑÇ¨TLK–UïÎy•W]πW∏n›∫˜EA∞UótQ´ª´Zñ$›X‚ubñ`âE{8 é÷4∂∏/c„∂˝l˙kê≠;m-HuÄ%‹tﬂsD\".©,\"æÃﬁÜÊ‰é∆z√ºnËïøNæ\'UºÈ.‹NùC«ih∏\ZÜ¶‚44Z|’q ≤Õ–U:#&à‡vöJ’¨¯|æ‰sˇl6ã~µä>¯ÄÍÍjÅ\0çoØ†“ì ÷Ω\r‹˘Ï&û7àÀF¢ ”çiY¸ÌHÑá◊º”k*ÏÍööÀbñeüM{¨ãô¬Ò∂0MÌab¶≠¿P[≈_√åÖèSsÀ\"∂èí°/IﬁÙá≤j·w8\'\'@]]˜˛h2ﬁcÎ…ª‰VB#Æ\'+Õ…ÊÕõyrÕ<⁄jè±ñP·’z√ƒ$zú¿%Kñ$‹µ˚lkZÌ·Î˛\Zdˇë4∑€DÆxes∫ÄÜÜ&Lò¿À;2˜\'¯≈=w0(3ÖöÚ|¶é(Ê¿ÅTVVBƒ§°°9Ir‘¥x˝—;:t(·®I[8í\Z>è˙˙zŸ∞aÉ<˜‹s≤{˜Ó3ö≠{\\⁄™™HÅ\'ïTß˜π‚…g|›´*∞~˚Å\0è/ö«/c î)L\Z]NyÅCUyø6qÏÿ1~t›^ﬂı)Å@Ä»[O2n¯@ﬁ;pî˜ˇ)ŸﬁkØΩ∆ﬂ˛∏MUp9t\Zö€»˜ÿIS[óŒπüäaÁ≤ˇ~>˝ÙSGí¯ç72m⁄¥ØÕCèË24Ò§:IqÍ(\"höä\'’AöÀÅC∑◊∫3Á›Àı7~èÛãsÿUwå@ ¿™%?•87CS9r¢Égﬂﬁ√•Á‡ÍoaﬁÇ{˘ÌÚ«Ê‚Û˘xhˆ%xRiÎäRîÂFÇG[P„1ßi	¡∆åøe1èá≠[∑R]]Õ§Iì\0ò={63fÃ†™™ä¬¬¬ØÕCèª∞\0¶eçö|“ÿ¬Ìw.¶3#jZƒ‚«”øZ@Ó†¡lÿ∞Ä÷p$Yn\' 3˘ı	‹¸ØsÒ˘|Ãü1çí‹tF\r…cLY>≠·({ÍO5-ÍCÌlˇ§ë}ıÕ|r‰ˇÒÁZb±«èg¡Ç<ÛÃ3\0233©¨¨<#Ú\0Ù3π˘ãêE¿«Ãu3fÚÎ_,$ÕÂ@SLâéòﬁx˜/úSî≈û√MºıÍc|V{êTßNÊ¿s\0í3¯;Oﬂ«´O.¬≤Ñå~Ídœ°Êxz⁄¬Q¢%<xÅ∆∆FnΩ|´7Ì\"¬oÓDS!%%Ö+ØºUµ5s—E—––p∆ˆˆ∏-[mñ≈5”øE^^ù—-ùé∑Üôwﬂ#l˚∏!9Ö£&ççç,]˛:jÓ`¶œ[¬#´◊r«Ì? ◊ìbÁ5ÖÃT\'9)§8t[·¶E‘4inÎbŒ“5<ª\0»ÀÀ„Xk∑€Õ¬y7”“—≈”ØÌb⁄¥iÏ›ªó™™*÷Ø_œµ◊^Àé;ŒÿﬁW Äw≈√ü`ŸÚﬂ1|¯pFé	¿M7Ã‚ΩM/Sªøûáû\\≈‰1Á≤Ë°<ˇÁW9tËc Û‡uSòÂ&fY*\"äÜ¶b …,uı\rwaóç,¶8\'ù_ø¯?^Ú(\0~\Z∞„≈∆F™™™hnnf¿Ä\0444–‘‘$YYYˇ8ìà¶*¢©äùi64é≈¯Å@Äπ7›Ä«ÌƒÌ‘Iw9y—Dñ=ıÜdRíõé°kh™B™S\'Õe$≥—ö¶¢)\nQÀ¢πΩãÊ∂.ÜJNz\nﬂö{\0´ı3Ü‰•s·Ï{»»»†££É¢¢\"æıTºi.Ó}ÏjjjX∫t)”ßOß££ÉΩ{˜2~¸¯Ø◊[˜uÌÌyé∞¶eœYi.\0f_?ìTßNä°°´*Q”‚/oΩ\n¿/öéHåTáN™S∑Àc	7µà∆L¢¶≈§[ÔÂŸ∑˜RÌ˛˚˝Oiô|Ú·|>◊7s·Ï{˘|¸|Ó\r¸a…è©ÆÆfﬁ¬póé$//ÄÇÇ<OIaaa…ôíΩ@`Yy9@rFM§óW=Û]3IJÃ¥PÖïø{äã/æ”\"¶I,^ﬁâq¥•ì˙¶véµÑiÈË¬ÁÛ1¶<üI#±¯ÆüxÂ]û}˙	Å\0;xåÏÏlÜfbZ·®…#ˇ˛\07›rÎ◊Øß££ÉU´VQSSÉ◊Î≠K=mè@S—5UúÜ&i.Cñ-}HDD2Sù2$/CÜÚ ®¡π2∂<ﬂ> Ú‰“s»îë≈2a¯@WQ ﬂùÚ\rI¿Ô˜ÀƒÛäolô\\>∫T¸~∑≤	√$ØOEÕπƒw¡yÛÕ7•∂∂VB°PÒŸÊÊÔB|]S%≈°Kö”H\ZXîÂñä¬L>»+U•92¶<_.:ßP.V$œ(~ø?IƒïS&»ÿa%\"\"2Ôá∑»‰ÉDDdÌ⁄µ2zpn≤^UiNÚ˘c Ú§∫,ODDFŒï+™K˚¸=…#;;;I`Çƒ+V»‚≈ã%”Ìî‚úÙ$â√dIE°G*\n3•™4WFŒMí1™4W¶é,ñ?˛~ïàà‰ë°π‚_JÂ Í¡…œ’ey2¶,O.V$¡`PB°ê\\\\Y¯œG^ß™––TqÍjíòÏ4ßî‰¶KqNz7ó{ˆŸ’rNQV≤^UiéL≠*ë	√äà$Î?µ‚Iπ†<_.(œëπsnÓˆúµk◊ Â˘r˘®í^≥≤≤‰TOü\\Mr3Rd«é‚˜˚%œì\"˘ûT…˜§HYæGDDJr”ÂÁ ÑÛl}xô,Ù·nd˘˝~Qú-ó+íØö&c Ûe¬År˘Ëæ!Ø«„¿`0(\r\r\rPV6$Ÿ¿·˙ﬁyÁ|>‡¸a§8t†p‡\0ñ=˛[é?Œ∑ø˝m d≥u«Gl€∂çÖ∑ﬂå7Õ≈˝O>«æΩ{xÍ◊?GE!5—4ÖTáNäS«eÿkÇD∆ªµ3¬[ªw≥Øææ^\0úNÁá/	Ù(Å°P®8++Î ¿“•K)--ÂjﬂUÄù±7	)ƒ,C◊HsÍ<˛‘JfŒö≈√Àñíõõ«ÃY≥»IO!=≈ ÿÿBA¶õ\"ØMÀ¬ﬁ’`hÒ›\nˆãyAàˇ“5Ÿ¸·!l“>˙Ë#öööíπAUU7n\\èŸ£q`WW◊A∞WÛÁœgÚ‰…|g˙U›Í¬Œù;Ò÷–5ô9k∑›6ó{Ô^¿OnªÄø_çi	[∂l·éªçY(ääC◊Ï,M8bé⁄ÁŒH,ynGì‰lŸ≤Ööö\ZˆÏŸÉ◊Î%\ZçbY´V≠b”¶Mœ4°⁄£kaß”Yx¡ô4iÅ@¿Œ üÇ—£™ÏïJÃ‰É>`‚ƒo≤Ú∑+íÂŸŸŸƒLãÆöÜ¢ÄÀ°éƒ–TU≈ﬁ\\§((ÿ˘?{˚á≠Úø~“ò$/\nø˘Êõ,]∫îöö\Z\n\n\nËÏÏ§ππôää\n6oﬁLaa·ó⁄\nÖäˇ/Öˆ(Å^Ø∑ŒÔ˜„Û˘x‚â\'»……!—G…EIr‹x·E?c«é¡≤_¸}n\"_5-tK–ÖÆ®ﬂTd≈˜÷ƒ]˜îˆñ%¸œg°nC“û={fgg≥wÔ^\Z\Z\Z»»»†≠≠çP(Daa!Üap¯a÷¨YìTaff&·pòX,∆Œù;	ÖB_ÈÊ=æî2d\0¿Âr1a¬Ñí)sÊÃ±+)\n+WÆL¶¥TUaÓ‹πö ¨◊r„¨òñ–ç—≥]≥3j“â—çé∆GÌÔ€√QZ:#ßëW__/„∆ç√0***á√‘’’ëûûŒ‹πs9q‚\'Nd◊Æ]Xñ≈ÙÈ”yÔΩ˜ÖBl‹∏ëH$ÿ¢¯*{{|>|¯ò¬¬¬˜ü˛yäããπ¬ï˙˙zŸ≤e™™2~¸¯í≤≤≤ÉÕÕMXñ$’dÛjªebÉe‚úÿÓ¶™J∑ã¿´oø∑`ƒàø¸|?^~˘eikkCUU™™™x<%ä¢‹πs\'[∑n•ººÀ≤p8ƒb1∫∫∫8zÙ(ÛÁœgıÍ’D£Q¶Nùz∆ÎØÖDÃ∑|˘ÚnÎœœ_ãà¨^ΩZUUNä\"\nà¶*‚–Ì5u™C∑”∑ÀêTß.Î÷≠{ˇÀ⁄É\"\"2gŒŸ∞aÉÑB°‚¯x(~ø_-Zd/ÁÕøﬂ/°PHÓ∏„Ò˚˝Ú–Cˆ∫}Â øooMØ∞ª{˜n©¨¨‰ÓªÔÊökÆa‘®Q_ÿN0îÊÊfJJJJ∆é{pˇæ}ß’9’ä%Kñp◊]w}eüõöödﬂæ}ÉA⁄€€©™™b‘®QäﬂÔÄññ233±,+yèiöå3ÜÌ€∑ã≈®®®¯“~˜:B°PÒK/Ω$]]]ß©∞/•ææ˛4ıü˙]‚s}}ΩÉA©≠≠ï›ªwK‚ﬁø∑≠^IÈ{Ωﬁ∫⁄⁄Z·p∏7ö¯J<¯4Âƒ\'ÂÀ>]Ù™DkkkËÊ\nÕÕÕ“ŸŸIWW—hîX,F,√≤,,À:ewÍI(Ò–E”¥¯õ8√0–uá√AJJ\nŸŸŸÈä¢¥ı¶=_Ñ>ıÒ∆∆F9zÙ(≠≠≠D\",À¬4Õdπ|¡6åœ#˚©™ä™™Ë∫é€Ì∆Îıíùùç€ÌÓSõ˙|ê<r‰HöÆÎ≠ëHÑh4J4\Z≈4Õ$ôüW_	¬TUE”4√Hû].èÁ‚o˙—è~Ù£˝ËG?˙—è~Ù£˝ËG?æˇ8·…7Ó£2À\0\0\0\0IENDÆB`Ç','Abidjan',15);
/*!40000 ALTER TABLE `infos_hotel` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `liberer_occup`
--

DROP TABLE IF EXISTS `liberer_occup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `liberer_occup` (
  `NumLiberer` int(11) NOT NULL AUTO_INCREMENT,
  `NumOccupation` int(11) NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  `CodeClient` int(11) NOT NULL,
  `Date` datetime NOT NULL,
  PRIMARY KEY (`NumLiberer`),
  KEY `MatriculeRecepteur` (`MatriculeRecepteur`),
  KEY `CodeClient` (`CodeClient`),
  KEY `NumOccupation` (`NumOccupation`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `liberer_occup`
--

LOCK TABLES `liberer_occup` WRITE;
/*!40000 ALTER TABLE `liberer_occup` DISABLE KEYS */;
/*!40000 ALTER TABLE `liberer_occup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `menu_resto`
--

DROP TABLE IF EXISTS `menu_resto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `menu_resto` (
  `IdMenuResto` int(11) NOT NULL AUTO_INCREMENT,
  `LibelleMenu` varchar(50) NOT NULL,
  `Prix` int(11) NOT NULL,
  `IdCatMenu` int(1) NOT NULL DEFAULT '0',
  `Supprime` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdMenuResto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `menu_resto`
--

LOCK TABLES `menu_resto` WRITE;
/*!40000 ALTER TABLE `menu_resto` DISABLE KEYS */;
/*!40000 ALTER TABLE `menu_resto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `message`
--

DROP TABLE IF EXISTS `message`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `message` (
  `NumMsg` int(11) NOT NULL AUTO_INCREMENT,
  `Contenu` varchar(160) NOT NULL,
  `Expediteur` varchar(10) NOT NULL,
  `Destinataire` varchar(10) NOT NULL,
  `HeureEnvoi` datetime NOT NULL,
  `Lue` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`NumMsg`),
  KEY `Expediteur` (`Expediteur`),
  KEY `Destinataire` (`Destinataire`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `message`
--

LOCK TABLES `message` WRITE;
/*!40000 ALTER TABLE `message` DISABLE KEYS */;
/*!40000 ALTER TABLE `message` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mode_de_payement`
--

DROP TABLE IF EXISTS `mode_de_payement`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mode_de_payement` (
  `IdModeDePayement` int(11) NOT NULL,
  `Mode` varchar(50) NOT NULL,
  PRIMARY KEY (`IdModeDePayement`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mode_de_payement`
--

LOCK TABLES `mode_de_payement` WRITE;
/*!40000 ALTER TABLE `mode_de_payement` DISABLE KEYS */;
INSERT INTO `mode_de_payement` VALUES (1,'Esp√®ce'),(2,'Ch√®que'),(3,'Carte de cr√©dit'),(4,'Compte client');
/*!40000 ALTER TABLE `mode_de_payement` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `occupation`
--

DROP TABLE IF EXISTS `occupation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `occupation` (
  `NumOccupation` int(11) NOT NULL AUTO_INCREMENT,
  `DateOccupation` datetime NOT NULL,
  `DureeOccupation` int(11) NOT NULL,
  `IdentiteCh` varchar(10) NOT NULL,
  `CoutDeLocation` int(11) NOT NULL DEFAULT '0',
  `FraisSupplementaire` int(11) NOT NULL DEFAULT '0',
  `CoutDeLocationPayee` int(11) NOT NULL DEFAULT '0',
  `DestinationExacte` varchar(70) DEFAULT NULL,
  `EnfAccMoinsDe15` int(11) NOT NULL DEFAULT '0',
  `CodeClient` int(11) NOT NULL,
  `Terminee` tinyint(4) NOT NULL DEFAULT '0',
  `FraisSupPayee` int(11) NOT NULL DEFAULT '0',
  `Facture` varchar(50) NOT NULL,
  `IdGroupe` int(11) NOT NULL DEFAULT '0',
  `IdProfile` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`NumOccupation`),
  KEY `IdentiteCh` (`IdentiteCh`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `occupation`
--

LOCK TABLES `occupation` WRITE;
/*!40000 ALTER TABLE `occupation` DISABLE KEYS */;
/*!40000 ALTER TABLE `occupation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `operations_comptable`
--

DROP TABLE IF EXISTS `operations_comptable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `operations_comptable` (
  `Id_opc` int(11) NOT NULL AUTO_INCREMENT,
  `NumeroOpc` int(11) NOT NULL,
  `Date` date NOT NULL,
  `Description` varchar(160) NOT NULL,
  `Credit` int(11) NOT NULL DEFAULT '0',
  `Debit` int(11) NOT NULL DEFAULT '0',
  `NumeroCompte` int(11) NOT NULL,
  `EnDiffere` tinyint(1) NOT NULL DEFAULT '0',
  `Supprime` tinyint(1) NOT NULL DEFAULT '0',
  `MatriculeAgent` varchar(50) NOT NULL,
  PRIMARY KEY (`Id_opc`),
  KEY `NumeroCompte` (`NumeroCompte`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `operations_comptable`
--

LOCK TABLES `operations_comptable` WRITE;
/*!40000 ALTER TABLE `operations_comptable` DISABLE KEYS */;
/*!40000 ALTER TABLE `operations_comptable` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `operations_compte_client`
--

DROP TABLE IF EXISTS `operations_compte_client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `operations_compte_client` (
  `IdOpCompteClient` int(11) NOT NULL AUTO_INCREMENT,
  `Date` datetime NOT NULL,
  `Libelle` varchar(160) NOT NULL,
  `Credit` int(11) NOT NULL DEFAULT '0',
  `Debit` int(11) NOT NULL DEFAULT '0',
  `Solde` int(11) NOT NULL DEFAULT '0',
  `IdCompteClient` int(11) NOT NULL,
  `MatriculeAgent` varchar(50) NOT NULL,
  PRIMARY KEY (`IdOpCompteClient`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `operations_compte_client`
--

LOCK TABLES `operations_compte_client` WRITE;
/*!40000 ALTER TABLE `operations_compte_client` DISABLE KEYS */;
/*!40000 ALTER TABLE `operations_compte_client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `operations_service`
--

DROP TABLE IF EXISTS `operations_service`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `operations_service` (
  `IdOperationService` int(11) NOT NULL AUTO_INCREMENT,
  `Recu` varchar(50) NOT NULL,
  `Date` datetime NOT NULL,
  `Libelle` varchar(100) NOT NULL,
  `MontantEncaisse` int(11) NOT NULL,
  `MatriculeAgent` varchar(50) NOT NULL,
  `Cloturee` tinyint(1) NOT NULL DEFAULT '0',
  `IdModeDePayement` int(11) NOT NULL DEFAULT '0',
  `IdTypeOperation` int(11) NOT NULL DEFAULT '0',
  `IdClotureService` int(11) NOT NULL DEFAULT '0',
  `IdTypeRecu` int(11) NOT NULL DEFAULT '0',
  `Depouille` tinyint(1) NOT NULL DEFAULT '0',
  `EstUneEntree` tinyint(1) NOT NULL DEFAULT '1',
  `TableTypeOperation` varchar(45) NOT NULL,
  PRIMARY KEY (`IdOperationService`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `operations_service`
--

LOCK TABLES `operations_service` WRITE;
/*!40000 ALTER TABLE `operations_service` DISABLE KEYS */;
/*!40000 ALTER TABLE `operations_service` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `piece_identite_client`
--

DROP TABLE IF EXISTS `piece_identite_client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `piece_identite_client` (
  `idPieceIdentite` int(11) NOT NULL AUTO_INCREMENT,
  `Nature` varchar(50) DEFAULT NULL,
  `Numero` varchar(50) DEFAULT NULL,
  `DateDelivrance` date DEFAULT NULL,
  `LieuDelivrance` varchar(50) DEFAULT NULL,
  `AgentDelivreur` varchar(160) DEFAULT NULL,
  `CodeClient` int(11) DEFAULT NULL,
  `DateReception` date DEFAULT NULL,
  `NumOccupation` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`idPieceIdentite`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `piece_identite_client`
--

LOCK TABLES `piece_identite_client` WRITE;
/*!40000 ALTER TABLE `piece_identite_client` DISABLE KEYS */;
/*!40000 ALTER TABLE `piece_identite_client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plan_comptable_syscohada`
--

DROP TABLE IF EXISTS `plan_comptable_syscohada`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `plan_comptable_syscohada` (
  `NumeroCompte` int(11) NOT NULL,
  `Libelle` varchar(225) NOT NULL,
  `LibellePerso` varchar(225) DEFAULT '',
  `Classe` int(11) NOT NULL DEFAULT '1',
  `Utilise` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`NumeroCompte`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plan_comptable_syscohada`
--

LOCK TABLES `plan_comptable_syscohada` WRITE;
/*!40000 ALTER TABLE `plan_comptable_syscohada` DISABLE KEYS */;
INSERT INTO `plan_comptable_syscohada` VALUES (10,'CAPITAL','CAPITAL',1,0),(11,'RESERVES','RESERVES',1,0),(12,'REPORT A NOUVEAU','REPORT A NOUVEAU',1,0),(13,'RESULTAT NET DE L\'EXERCICE','RESULTAT NET DE L\'EXERCICE',1,0),(14,'SUBVENTIONS D\'INVESTISSEMENT','SUBVENTIONS D\'INVESTISSEMENT',1,0),(15,'PROVISIONS REGLEMENTEES ET FONDS ASSIMILES','PROVISIONS REGLEMENTEES ET FONDS ASSIMILES',1,0),(16,'EMPRUNTS ET DETTES ASSIMILEES','EMPRUNTS ET DETTES ASSIMILEES',1,0),(17,'DETTES DE CREDIT - BAIL ET CONTRATS ASSIMILES','DETTES DE CREDIT - BAIL ET CONTRATS ASSIMILES',1,0),(18,'DETTES LIEES A DES PARTICIPATIONS ET COMPTES DE LIAISON DES ETABLISSEMENTS ET SOCIETIES EN PARTICIPATION','DETTES LIEES A DES PARTICIPATIONS ET COMPTES DE LIAISON DES ETABLISSEMENTS ET SOCIETIES EN PARTICIPATION',1,0),(19,'PROVIISIONS FINANCIERES POUR RISQUES ET CHARGES','PROVIISIONS FINANCIERES POUR RISQUES ET CHARGES',1,0),(20,'CHARGES IMMOBILISEES','CHARGES IMMOBILISEES',2,0),(21,'IMMOBILISATIONS INCORPORELLES','IMMOBILISATIONS INCORPORELLES',2,0),(22,'TERRAINS','TERRAINS',2,0),(23,'BATIMENTS, INSTALLATIONS TECHNIQUES ET AGENCEMENTS','BATIMENTS, INSTALLATIONS TECHNIQUES ET AGENCEMENTS',2,0),(24,'MATERIEL','MATERIEL',2,0),(25,'AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS','AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS',2,0),(26,'TITRES DE PARTICIPATION','TITRES DE PARTICIPATION',2,0),(27,'AUTRES IMMOBILISATIONS FINANCIERES','AUTRES IMMOBILISATIONS FINANCIERES',2,0),(28,'AMORTISSEMENTS','AMORTISSEMENTS',2,0),(29,'PROVISIONS POUR DEPRECIATION','PROVISIONS POUR DEPRECIATION',2,0),(31,'MARCHANDISES','MARCHANDISES',3,0),(32,'MATIERES PREMIERES ET FOURNITURES LIEES','MATIERES PREMIERES ET FOURNITURES LIEES',3,0),(34,'PRODUITS EN COURS','PRODUITS EN COURS',3,0),(35,'SERVICES EN COURS','SERVICES EN COURS',3,0),(36,'PRODUITS FINIS','PRODUITS FINIS',3,0),(37,'PRODUITS INTERMEDIAIRES ET RESIDUELS','PRODUITS INTERMEDIAIRES ET RESIDUELS',3,0),(38,'STOCKS EN COURS DE ROUTE, EN CONSIGNATION OU EN DEPOT','STOCKS EN COURS DE ROUTE, EN CONSIGNATION OU EN DEPOT',3,0),(39,'DEPRECIATIONS DES STOCKS','DEPRECIATIONS DES STOCKS',3,0),(40,'FOURNISSEURS ET COMPTES RATTACHES','FOURNISSEURS ET COMPTES RATTACHES',4,0),(41,'CLIENTS ET COMPTES RATTACHES','CLIENTS ET COMPTES RATTACHES',4,0),(42,'PERSONNEL','PERSONNEL',4,0),(43,'ORGANISMES SOCIAUX','ORGANISMES SOCIAUX',4,0),(44,'ETAT ET COLLECTIVITES PUBLIQUES','ETAT ET COLLECTIVITES PUBLIQUES',4,0),(45,'ORGANISMES INTERNATIONAUX ','ORGANISMES INTERNATIONAUX ',4,0),(46,'ASSOCIES ET GROUPE','ASSOCIES ET GROUPE',4,0),(47,'DEBITEURS ET CREDITEURS DIVERS','DEBITEURS ET CREDITEURS DIVERS',4,0),(48,'CREANCES ET DETTES HORS ACTIVITES ORDINAIRES (HAO)','CREANCES ET DETTES HORS ACTIVITES ORDINAIRES (HAO)',4,0),(49,'DEPRECIATIONS ET RISQUES PROVISIONNES (TIERS)','DEPRECIATIONS ET RISQUES PROVISIONNES (TIERS)',4,0),(50,'TITRES DE PLACEMENT','TITRES DE PLACEMENT',5,0),(51,'VALEURS A ENCAISSER','VALEURS A ENCAISSER',5,0),(52,'BANQUES','Ma banque',5,1),(53,'ETABLISSEMENTS FINANCIERS ASSIMILES','ETABLISSEMENTS FINANCIERS ASSIMILES',5,0),(54,'INSTRUMENTS DE TRESORERIE','INSTRUMENTS DE TRESORERIE',5,0),(56,'BANQUES, CREDITS DE TRESORERIE ET D\'ESCOMPTE','BANQUES, CREDITS DE TRESORERIE ET D\'ESCOMPTE',5,0),(57,'CAISSE','Ma caisse',5,1),(58,'REGIES D\'AVANCES, ACCREDITIFS ET VIREMENTS INTERNES','REGIES D\'AVANCES, ACCREDITIFS ET VIREMENTS INTERNES',5,0),(59,'DEPRECIATIONS ET RISQUES PROVISIONNES','DEPRECIATIONS ET RISQUES PROVISIONNES',5,0),(60,'ACHATS ET VARIATIONS DE STOCKS','ACHATS ET VARIATIONS DE STOCKS',6,0),(61,'TRANSPORTS','TRANSPORTS',6,0),(62,'SERVICES EXTERIEURS A','SERVICES EXTERIEURS A',6,0),(63,'SERVICES EXTERIEURS B','SERVICES EXTERIEURS B',6,0),(64,'IMPOTS ET TAXES','IMPOTS ET TAXES',6,0),(65,'AUTRES CHARGES','AUTRES CHARGES',6,0),(66,'CHARGES DE PERSONNEL','CHARGES DE PERSONNEL',6,0),(67,'FRAIS FINANCIERS ET CHARGES ASSIMILEES','FRAIS FINANCIERS ET CHARGES ASSIMILEES',6,0),(68,'DOTATIONS AUX AMORTISSEMENTS','DOTATIONS AUX AMORTISSEMENTS',6,0),(69,'DOTATIONS AUX PROVISIONS','DOTATIONS AUX PROVISIONS',6,0),(70,'VENTES','VENTES',7,0),(71,'SUBVENTIONS D\'EXPLOITATION','SUBVENTIONS D\'EXPLOITATION',7,0),(72,'PRODUCTION IMMOBILISEE','PRODUCTION IMMOBILISEE',7,0),(73,'VARIATIONS DES STOCKS DE BIENS ET DE SERVICES PRODUITS','VARIATIONS DES STOCKS DE BIENS ET DE SERVICES PRODUITS',7,0),(75,'AUTRES PRODUITS','AUTRES PRODUITS',7,0),(77,'REVENUS FINANCIERS ET PRODUITS ASSIMILES','REVENUS FINANCIERS ET PRODUITS ASSIMILES',7,0),(78,'TRANSFERTS DE CHARGES','TRANSFERTS DE CHARGES',7,0),(79,'REPRISES DE PROVISIONS','REPRISES DE PROVISIONS',7,0),(81,'VAEURS COMPTABLES DES CESSIONS D\'IMMOBILISATIONS','VAEURS COMPTABLES DES CESSIONS D\'IMMOBILISATIONS',8,0),(82,'PRODUITS DES CESSIONS D\'IMMOBILISATIONS','PRODUITS DES CESSIONS D\'IMMOBILISATIONS',8,0),(83,'CHARGES HORS ACTIVITES ORDINAIRES','CHARGES HORS ACTIVITES ORDINAIRES',8,0),(84,'PRODUITS HORS ACTIVITES ORDINAIRES ','PRODUITS HORS ACTIVITES ORDINAIRES ',8,1),(85,'DOTATIONS HORS ACTIVITES ORDINAIRES','DOTATIONS HORS ACTIVITES ORDINAIRES',8,0),(86,'REPRISES HORS ACTIVITES ORDINAIRES','REPRISES HORS ACTIVITES ORDINAIRES',8,0),(87,'PARTICIPATION DES TRAVAILLEURS','PARTICIPATION DES TRAVAILLEURS',8,0),(88,'SUBVENTIONS D\'EQUILIBRE','SUBVENTIONS D\'EQUILIBRE',8,0),(89,'IMPOTS SUR LE RESULTAT','IMPOTS SUR LE RESULTAT',8,0),(90,'ENGAGEMENTS OBTENUS ET ENGAGEMENTS ACCORDES','ENGAGEMENTS OBTENUS ET ENGAGEMENTS ACCORDES',9,0),(91,'CONTREPARTIES DES ENGAGEMENTS','CONTREPARTIES DES ENGAGEMENTS',9,0),(92,'COMPTES REFLECHIS','COMPTES REFLECHIS',9,0),(93,'COMPTES DE RECLASSEMENTS','COMPTES DE RECLASSEMENTS',9,0),(94,'COMPTES DE CO√õTS','COMPTES DE CO√õTS',9,0),(95,'COMPTES DE STOCKS','COMPTES DE STOCKS',9,0),(96,'COMPTES D\'ECARTS SUR CO√õTS PREETABLIS','COMPTES D\'ECARTS SUR CO√õTS PREETABLIS',9,0),(97,'COMPTES DE DIFFERENCES DE TRAITEMENT COMPTABLE','COMPTES DE DIFFERENCES DE TRAITEMENT COMPTABLE',9,0),(101,'CAPITAL SOCIAL','CAPITAL SOCIAL',1,0),(102,'CAPITAL PAR DOTATION','CAPITAL PAR DOTATION',1,0),(103,'CAPITAL PERSONNEL','CAPITAL PERSONNEL',1,0),(104,'COMPTE DE L\'EXPLOITANT','COMPTE DE L\'EXPLOITANT',1,0),(105,'PRIMES LIEES AUX CAPITAUX PROPRES','PRIMES LIEES AUX CAPITAUX PROPRES',1,0),(106,'ECARTS DE REEVALUATION','ECARTS DE REEVALUATION',1,0),(109,'ACTIONNAIRES, CAPITAL SOUSCRIT, NON APPELE','ACTIONNAIRES, CAPITAL SOUSCRIT, NON APPELE',1,0),(111,'RESERVE LEGALE','RESERVE LEGALE',1,0),(112,'RESERVES STATUTAIRES OU CONTRACTUELLES','RESERVES STATUTAIRES OU CONTRACTUELLES',1,0),(113,'RESERVES REGLEMENTEES','RESERVES REGLEMENTEES',1,0),(118,'AUTRES RESERVES','AUTRES RESERVES',1,0),(121,'REPORT A NOUVEAU CREDITEUR','REPORT A NOUVEAU CREDITEUR',1,0),(129,'REPORT A NOUVEAU DEBITEUR','REPORT A NOUVEAU DEBITEUR',1,0),(130,'RESULTAT EN INSTANCE D\'AFFECTATION','RESULTAT EN INSTANCE D\'AFFECTATION',1,0),(131,'RESULTAT NET : BENEFICE','RESULTAT NET : BENEFICE',1,0),(132,'MARGE BRUTE (M.B.)','MARGE BRUTE (M.B.)',1,0),(133,'VALEUR AJOUTEE (V.A.)','VALEUR AJOUTEE (V.A.)',1,0),(134,'EXCEDENT BRUT D\'EXPLOITATION (E.B.E.)','EXCEDENT BRUT D\'EXPLOITATION (E.B.E.)',1,0),(135,'RESULTAT D\'EXPLOITATIN (R.E.)','RESULTAT D\'EXPLOITATIN (R.E.)',1,0),(136,'RESULTAT FINANCIER (R.F.)','RESULTAT FINANCIER (R.F.)',1,0),(137,'RESULTAT DES ACTIVITES ORDINAIRES (R.A.O.)','RESULTAT DES ACTIVITES ORDINAIRES (R.A.O.)',1,0),(138,'RESULTAT HORS ACTIVITES ORDINAIRES (R.H.A.O.)','RESULTAT HORS ACTIVITES ORDINAIRES (R.H.A.O.)',1,0),(139,'RESULTAT NET : PERTE','RESULTAT NET : PERTE',1,0),(141,'SUBVENTIONS D\'EQUIPEMENT A','SUBVENTIONS D\'EQUIPEMENT A',1,0),(142,'SUBVENTIONS D\'EQUIPEMENT B','SUBVENTIONS D\'EQUIPEMENT B',1,0),(148,'AUTRES SUBVENTIONS D\'INVESTISSEMENT ','AUTRES SUBVENTIONS D\'INVESTISSEMENT ',1,0),(151,'AMORTISSEMENTS DEROGATOIRES','AMORTISSEMENTS DEROGATOIRES',1,0),(152,'PLUS-VALUES DE CESSION A REINVESTIR','PLUS-VALUES DE CESSION A REINVESTIR',1,0),(153,'FONDS REGLEMENTES','FONDS REGLEMENTES',1,0),(154,'PROVISION SPECIALE DE REEVALUATION','PROVISION SPECIALE DE REEVALUATION',1,0),(155,'PROVISIONS REGLEMENTEES RELATIVES AUX IMMOBILISATIONS','PROVISIONS REGLEMENTEES RELATIVES AUX IMMOBILISATIONS',1,0),(156,'PROVISIONS REGLEMENTEES RELATIVES AUX STOCKS','PROVISIONS REGLEMENTEES RELATIVES AUX STOCKS',1,0),(157,'PROVISIONS POUR INVESTISSEMENT','PROVISIONS POUR INVESTISSEMENT',1,0),(158,'AUTRES PROVISIONS ET FONDS REGLEMENTES','AUTRES PROVISIONS ET FONDS REGLEMENTES',1,0),(161,'EMPRUNTS OBLIGATAIRES','EMPRUNTS OBLIGATAIRES',1,0),(162,'EMPRUNTS ET DETTES AUPRES DES ETABLISSEMENTS DE CREDIT ','EMPRUNTS ET DETTES AUPRES DES ETABLISSEMENTS DE CREDIT ',1,0),(163,'AVANCES RECUES DE L\'ETAT','AVANCES RECUES DE L\'ETAT',1,0),(164,'AVANCES RECUES ET COMPTES COURANTS BLOQUES','AVANCES RECUES ET COMPTES COURANTS BLOQUES',1,0),(165,'DEPOTS ET CAUTIONNEMENTS RECUS','DEPOTS ET CAUTIONNEMENTS RECUS',1,0),(166,'INTERETS COURUS','INTERETS COURUS',1,0),(167,'AVANCES ASSORTIES DE CONDITIONS PARTICULIERES','Avance sur location',1,1),(168,'AUTRES EMPRUNTS ET DETTES','AUTRES EMPRUNTS ET DETTES',1,0),(172,'EMPRUNTS EQUIVALENTS DE CREDIT - BAIL IMMOBILIER','EMPRUNTS EQUIVALENTS DE CREDIT - BAIL IMMOBILIER',1,0),(173,'EMPRUNTS EQUIVALENTS DE CREDIT - BAIL MOBILIER','EMPRUNTS EQUIVALENTS DE CREDIT - BAIL MOBILIER',1,0),(176,'INTERETS COURUS','INTERETS COURUS',1,0),(178,'EMPRUNTS EQUIVALENTS D\'AUTRES CONTRATS','EMPRUNTS EQUIVALENTS D\'AUTRES CONTRATS',1,0),(181,'DETTES LIEES A DES PARTICIPATIONS','DETTES LIEES A DES PARTICIPATIONS',1,0),(182,'DETTES LIEES A DES SOCIETES EN PARTICIPATION','DETTES LIEES A DES SOCIETES EN PARTICIPATION',1,0),(183,'INTER√äTS COURUS SUR DETTES LIEES A DES PARTICIPATIONS','INTER√äTS COURUS SUR DETTES LIEES A DES PARTICIPATIONS',1,0),(184,'COMPTES PERMANENTS BLOQUES DES ETABLISSEMENTS ET SUCCURSALES','COMPTES PERMANENTS BLOQUES DES ETABLISSEMENTS ET SUCCURSALES',1,0),(185,'COMPTES PERMANENTS NON BLOQUES DES ETABLISSEMENTS ET SUCCURSALES ','COMPTES PERMANENTS NON BLOQUES DES ETABLISSEMENTS ET SUCCURSALES ',1,0),(186,'COMPTES DE LIAISON CHARGES','COMPTES DE LIAISON CHARGES',1,0),(187,'COMPTES DE LIAISON PRODUITS','COMPTES DE LIAISON PRODUITS',1,0),(188,'COMPTES DE LIAISON DES SOCIETES EN PARTICIPATION','COMPTES DE LIAISON DES SOCIETES EN PARTICIPATION',1,0),(191,'PROVISIONS POUR LITIGES','PROVISIONS POUR LITIGES',1,0),(192,'PROVISIONS POUR GARANTIES DONNEES AUX CLIENTS','PROVISIONS POUR GARANTIES DONNEES AUX CLIENTS',1,0),(193,'PROVISIONS POUR PERTES SUR MARCHES A ACHEVEMENT FUTUR','PROVISIONS POUR PERTES SUR MARCHES A ACHEVEMENT FUTUR',1,0),(194,'PROVISIONS POUR PERTES DE CHANGE','PROVISIONS POUR PERTES DE CHANGE',1,0),(195,'PROVISIONS POUR IMP√îTS','PROVISIONS POUR IMP√îTS',1,0),(196,'PROVISIONS POUR PENSIONS ET OBLIGATIONS SIMILAIRES','PROVISIONS POUR PENSIONS ET OBLIGATIONS SIMILAIRES',1,0),(197,'PROVISIONS POUR CHARGES A REPARTIR SUR PLUSIEURS EXERCICES','PROVISIONS POUR CHARGES A REPARTIR SUR PLUSIEURS EXERCICES',1,0),(198,'AUTRES PROVISIONS FINANCIERES POUR RISQUES  ET CHARGES','AUTRES PROVISIONS FINANCIERES POUR RISQUES  ET CHARGES',1,0),(201,'FRAIS D\'ETABLISSEMENT','FRAIS D\'ETABLISSEMENT',2,0),(202,'CHARGES A REPARTIR SUR PLUSIEURS EXERCICES','CHARGES A REPARTIR SUR PLUSIEURS EXERCICES',2,0),(206,'PRIMES DE REMBOURSEMENT DES OBLIGATIONS','PRIMES DE REMBOURSEMENT DES OBLIGATIONS',2,0),(211,'FRAIS DE RECHERCHE ET DE DEVELOPPEMENT','FRAIS DE RECHERCHE ET DE DEVELOPPEMENT',2,0),(212,'BREVETS, LICENCES, CONCESSIONS ET DROITS SIMILAIRES','BREVETS, LICENCES, CONCESSIONS ET DROITS SIMILAIRES',2,0),(213,'LOGICIELS','LOGICIELS',2,0),(214,'MARQUES','MARQUES',2,0),(215,'FONDS COMMERCIAL','FONDS COMMERCIAL',2,0),(216,'DROIT AU BAIL','DROIT AU BAIL',2,0),(217,'INVESTISSEMENTS DE CREATION','INVESTISSEMENTS DE CREATION',2,0),(218,'AUTRES DROITS ET VALEURS INCORPORELS','AUTRES DROITS ET VALEURS INCORPORELS',2,0),(219,'IMMOBILISATIONS INCORPORELLES EN COURS','IMMOBILISATIONS INCORPORELLES EN COURS',2,0),(221,'TERRAINS AGRICOLES ET FORESTIERS','TERRAINS AGRICOLES ET FORESTIERS',2,0),(222,'TERRAINS NUS','TERRAINS NUS',2,0),(223,'TERRAINS BATIS','TERRAINS BATIS',2,0),(224,'TRAVAUX DE MISE EN VALEUR DES TERRAINS','TRAVAUX DE MISE EN VALEUR DES TERRAINS',2,0),(225,'TERRAINS DE GISEMENT','TERRAINS DE GISEMENT',2,0),(226,'TERRAINS AMENAGES','TERRAINS AMENAGES',2,0),(227,'TERRAINS MIS EN CONCESSION','TERRAINS MIS EN CONCESSION',2,0),(228,'AUTRES TERRAINS','AUTRES TERRAINS',2,0),(229,'AMENAGEMENTS DE TERRAINS EN COURS','AMENAGEMENTS DE TERRAINS EN COURS',2,0),(231,'BATIMENTS INDUSTRIELS, AGRICOLES, ADMINISTRATIFS ET COMMERCIAUX SUR SOL PROPRE','BATIMENTS INDUSTRIELS, AGRICOLES, ADMINISTRATIFS ET COMMERCIAUX SUR SOL PROPRE',2,0),(232,'BATIMENTS INDUSTRIELS, AGRICOLES, ADMINISTRATIFS ET COMMERCIAUX SUR SOL D\'AUTRUI','BATIMENTS INDUSTRIELS, AGRICOLES, ADMINISTRATIFS ET COMMERCIAUX SUR SOL D\'AUTRUI',2,0),(233,'OUVRAGES D\'INFRASTRUTURE','OUVRAGES D\'INFRASTRUTURE',2,0),(234,'INSTALLATIONS TECHNIQUES','INSTALLATIONS TECHNIQUES',2,0),(235,'AMENAGEMENTS DE BUREAUX','AMENAGEMENTS DE BUREAUX',2,0),(237,'BATIMENTS INDUSTRIELS, AGRICOLES ET COMMERCIAUX MIS EN CONCESSION','BATIMENTS INDUSTRIELS, AGRICOLES ET COMMERCIAUX MIS EN CONCESSION',2,0),(238,'AUTRES INSTALLATIONS ET AGENCEMENTS','AUTRES INSTALLATIONS ET AGENCEMENTS',2,0),(239,'BATIMENTS ET INSTALLATIONS EN COURS','BATIMENTS ET INSTALLATIONS EN COURS',2,0),(241,'MATERIEL ET OUTILLAGE INDUSTRIEL ET COMMERCIAL','MATERIEL ET OUTILLAGE INDUSTRIEL ET COMMERCIAL',2,0),(242,'MATERIEL ET OUTILLAGE AGRICOLE','MATERIEL ET OUTILLAGE AGRICOLE',2,0),(243,'MATERIEL D\'EMBALLAGE RECUPERABLE ET IDENTIFIABLE','MATERIEL D\'EMBALLAGE RECUPERABLE ET IDENTIFIABLE',2,0),(244,'MATERIEL ET MOBILIER','MATERIEL ET MOBILIER',2,0),(245,'MATERIEL DE TRANSPORT','MATERIEL DE TRANSPORT',2,0),(246,'IMMOBILISATIONS ANIMALES ET AGRICOLES','IMMOBILISATIONS ANIMALES ET AGRICOLES',2,0),(247,'AGENCEMENTS ET AMENAGEMENTS DU MATERIEL','AGENCEMENTS ET AMENAGEMENTS DU MATERIEL',2,0),(248,'AUTRES MATERIELS','AUTRES MATERIELS',2,0),(249,'MATERIEL EN COURS','MATERIEL EN COURS',2,0),(251,'AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS INCORPORELLES','AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS INCORPORELLES',2,0),(252,'AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS CORPORELLES','AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS CORPORELLES',2,0),(261,'TITRES DE PARTICIPATION DANS DES SOCIETES SOUS CONTROLE EXCLUSIF','TITRES DE PARTICIPATION DANS DES SOCIETES SOUS CONTROLE EXCLUSIF',2,0),(262,'TITRES DE PARTICIPATION DANS DES SOCIETES SOUS CONTROLE CONJOINT','TITRES DE PARTICIPATION DANS DES SOCIETES SOUS CONTROLE CONJOINT',2,0),(263,'TITRES DE PARTICIPATION DANS DES SOCIETES CONFERANT UNE INFLUENCE NOTABLE','TITRES DE PARTICIPATION DANS DES SOCIETES CONFERANT UNE INFLUENCE NOTABLE',2,0),(265,'PARTICIPATIONS DANS DES ORGANISMES PROFESSIONNELS','PARTICIPATIONS DANS DES ORGANISMES PROFESSIONNELS',2,0),(266,'PARTS DANS DES GROUPEMENTS D\'INTERET ECONOMIQUE (G.I.E.)','PARTS DANS DES GROUPEMENTS D\'INTERET ECONOMIQUE (G.I.E.)',2,0),(268,'AUTRES TITRES DE PARTICIPATION','AUTRES TITRES DE PARTICIPATION',2,0),(271,'PRETS ET CREANCES NON COMMERCIALES','PRETS ET CREANCES NON COMMERCIALES',2,0),(272,'PRETS AU PERSONNEL','PRETS AU PERSONNEL',2,0),(273,'CREANCES SUR L\'ETAT','CREANCES SUR L\'ETAT',2,0),(274,'TITRES IMMOBILISES','TITRES IMMOBILISES',2,0),(275,'DEPOTS ET CAUTIONNEMENTS VERSES','DEPOTS ET CAUTIONNEMENTS VERSES',2,0),(276,'INTERETS COURUS','INTERETS COURUS',2,0),(277,'CREANCES RATTACHEES A DES PARTICIPATIONS ET AVANCES A DES G.I.E.','CREANCES RATTACHEES A DES PARTICIPATIONS ET AVANCES A DES G.I.E.',2,0),(278,'IMMOBILISATIONS FINANCIERES DIVERSES','IMMOBILISATIONS FINANCIERES DIVERSES',2,0),(281,'AMORTISSEMENTS DES IMMOBILISATIONS INCORPORELLES','AMORTISSEMENTS DES IMMOBILISATIONS INCORPORELLES',2,0),(282,'AMORTISSEMENTS DES TERRAINS','AMORTISSEMENTS DES TERRAINS',2,0),(283,'AMORTISSEMENTS DES BATIMENTS, INSTALLATIONS TECHNIQUES ET AGENCEMENTS','AMORTISSEMENTS DES BATIMENTS, INSTALLATIONS TECHNIQUES ET AGENCEMENTS',2,0),(284,'AMORTISSEMENTS DU MATERIEL','AMORTISSEMENTS DU MATERIEL',2,0),(291,'PROVISIONS POUR DEPRECIATION DES IMMOBILISATIONS INCORPORELLES','PROVISIONS POUR DEPRECIATION DES IMMOBILISATIONS INCORPORELLES',2,0),(292,'PROVISIONS POUR DEPRECIATION DES TERRAINS','PROVISIONS POUR DEPRECIATION DES TERRAINS',2,0),(293,'PROVISIONS POUR DEPRECIATION DES BATIMENTS, INSTALLATIONS TECHNIQUES ET AGENCEMENTS','PROVISIONS POUR DEPRECIATION DES BATIMENTS, INSTALLATIONS TECHNIQUES ET AGENCEMENTS',2,0),(294,'PROVISIONS POUR DEPRECIATION DE MATERIEL','PROVISIONS POUR DEPRECIATION DE MATERIEL',2,0),(295,'PROVISIONS POUR DEPRECIATION DES AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS','PROVISIONS POUR DEPRECIATION DES AVANCES ET ACOMPTES VERSES SUR IMMOBILISATIONS',2,0),(296,'PROVISIONS POUR DEPRECIATION DES TITRES DE PARTICIPATION','PROVISIONS POUR DEPRECIATION DES TITRES DE PARTICIPATION',2,0),(297,'PROVISIONS POUR DEPRECIATION DES AUTRES IMMOBILISATIONS FINANCIERES','PROVISIONS POUR DEPRECIATION DES AUTRES IMMOBILISATIONS FINANCIERES',2,0),(311,'MARCHANDISES A','MARCHANDISES A',3,0),(312,'MARCHANDISES B','MARCHANDISES B',3,0),(318,'MARCHANDISES HORS ACTIVITES ORDINAIRES (H.A.O.)','MARCHANDISES HORS ACTIVITES ORDINAIRES (H.A.O.)',3,0),(321,'MATIERES A','MATIERES A',3,0),(322,'MATIERES B','MATIERES B',3,0),(323,'FOURNITURES (A,B)','FOURNITURES (A,B)',3,0),(333,'FOURNITURES DE MAGASIN','FOURNITURES DE MAGASIN',3,0),(334,'FOURNITURES DE BUREAU','FOURNITURES DE BUREAU',3,0),(335,'EMBALLAGES','EMBALLAGES',3,0),(338,'AUTRES MATIERES','AUTRES MATIERES',3,0),(341,'PRODUITS EN COURS','PRODUITS EN COURS',3,0),(342,'TRAVAUX EN COURS','TRAVAUX EN COURS',3,0),(343,'PRODUITS INTERMEDIAIRES EN COURS','PRODUITS INTERMEDIAIRES EN COURS',3,0),(344,'PRODUITS RESIDUELS EN COURS','PRODUITS RESIDUELS EN COURS',3,0),(351,'ETUDES EN COURS','ETUDES EN COURS',3,0),(361,'PRODUITS FINIS A','PRODUITS FINIS A',3,0),(362,'PRODUITS FINIS B','PRODUITS FINIS B',3,0),(371,'PRODUITS INTERMEDIAIRES','PRODUITS INTERMEDIAIRES',3,0),(372,'PRODUITS RESIDUELS','PRODUITS RESIDUELS',3,0),(381,'MARCHANDISES EN COURS DE ROUTE','MARCHANDISES EN COURS DE ROUTE',3,0),(382,'MATIERES PREMIERES ET FOURNITURES LIEES EN COURS DE ROUTE','MATIERES PREMIERES ET FOURNITURES LIEES EN COURS DE ROUTE',3,0),(383,'AUTRES APPROVISIONNEMENTS EN COURS DE ROUTE','AUTRES APPROVISIONNEMENTS EN COURS DE ROUTE',3,0),(386,'PRODUITS FINIS EN COURS DE ROUTE','PRODUITS FINIS EN COURS DE ROUTE',3,0),(387,'STOCK EN CONSIGNATION OU EN DEPOT','STOCK EN CONSIGNATION OU EN DEPOT',3,0),(388,'STOCK PROVENANT D\'IMMOBILISATIONS MISES HORS SERVICE OU AU REBUT','STOCK PROVENANT D\'IMMOBILISATIONS MISES HORS SERVICE OU AU REBUT',3,0),(391,'DEPRECIATIONS DES STOCKS DE MARCHANDISES','DEPRECIATIONS DES STOCKS DE MARCHANDISES',3,0),(392,'DEPRECIATIONS DES STOCKS DE MATIERES PREMIERES ET FOURNITURES LIEES','DEPRECIATIONS DES STOCKS DE MATIERES PREMIERES ET FOURNITURES LIEES',3,0),(393,'DEPRECIATIONS DES STOCKS D\'AUTRES APPROVISIONNEMENTS','DEPRECIATIONS DES STOCKS D\'AUTRES APPROVISIONNEMENTS',3,0),(394,'DEPRECIATIONS DES PRODUCTIONS EN COURS','DEPRECIATIONS DES PRODUCTIONS EN COURS',3,0),(395,'DEPRECIATIONS DES SERVICES EN COURS','DEPRECIATIONS DES SERVICES EN COURS',3,0),(396,'DEPRECIATIONS DES STOCKS DE PRODUITS FINIS','DEPRECIATIONS DES STOCKS DE PRODUITS FINIS',3,0),(397,'DEPRECIATIONS DES STOCKS DE PRODUITS INTERMEDIAIRES ET RESIDUELS','DEPRECIATIONS DES STOCKS DE PRODUITS INTERMEDIAIRES ET RESIDUELS',3,0),(398,'DEPRECIATIONS DES STOCKS EN COURS DE ROUTE, EN CONSIGNATION OU EN DEPOT','DEPRECIATIONS DES STOCKS EN COURS DE ROUTE, EN CONSIGNATION OU EN DEPOT',3,0),(401,'FOURNISSEURS, DETTES EN COMPTE','FOURNISSEURS, DETTES EN COMPTE',4,0),(402,'FOURNISSEURS, EFFETS A PAYER','FOURNISSEURS, EFFETS A PAYER',4,0),(408,'FOURNISSEURS, FACTURES NON PARVENUES','FOURNISSEURS, FACTURES NON PARVENUES',4,0),(409,'FOURNISSEURS DEBITEURS','FOURNISSEURS DEBITEURS',4,0),(411,'CLIENTS','CLIENTS',4,0),(412,'CLIENTS, EFFETS A RECEVOIR EN PORTEFEUILLE','CLIENTS, EFFETS A RECEVOIR EN PORTEFEUILLE',4,0),(414,'CREANCES SUR CESSIONS D\'IMMOBILISATIONS','CREANCES SUR CESSIONS D\'IMMOBILISATIONS',4,0),(415,'CLIENTS, EFFETS ESCOMPTES NON ECHUS','CLIENTS, EFFETS ESCOMPTES NON ECHUS',4,0),(416,'CREANCES CLIENTS LITIGIEUSES OU DOUTEUSES','CREANCES CLIENTS LITIGIEUSES OU DOUTEUSES',4,0),(418,'CLIENTS, PRODUITS A RECEVOIR','CLIENTS, PRODUITS A RECEVOIR',4,0),(419,'CLIENTS CREDITEURS','CLIENTS CREDITEURS',4,0),(421,'PERSONNEL, AVANCES ET ACOMPTES','PERSONNEL, AVANCES ET ACOMPTES',4,0),(422,'PERSONNEL, REMUNERATIONS DUES','PERSONNEL, REMUNERATIONS DUES',4,0),(423,'PERSONNEL, OPPOSITIONS, SAISIES-ARRETS','PERSONNEL, OPPOSITIONS, SAISIES-ARRETS',4,0),(424,'PERSONNEL, OEUVRES SOCIALES INTERNES','PERSONNEL, OEUVRES SOCIALES INTERNES',4,0),(425,'REPRESENTANTS DU PERSONNEL','REPRESENTANTS DU PERSONNEL',4,0),(426,'PERSONNEL, PARTICIPATION AUX BENEFICES','PERSONNEL, PARTICIPATION AUX BENEFICES',4,0),(427,'PERSONNEL-DEPOTS','PERSONNEL-DEPOTS',4,0),(428,'PERSONNEL, CHARGES A PAYER ET PRODUITS A RECEVOIR','PERSONNEL, CHARGES A PAYER ET PRODUITS A RECEVOIR',4,0),(431,'SECURITE SOCIALE','SECURITE SOCIALE',4,0),(432,'CAISSES DE RETRAITE COMPLEMENTAIRE','CAISSES DE RETRAITE COMPLEMENTAIRE',4,0),(433,'AUTRES ORGANISMES SOCIAUX','AUTRES ORGANISMES SOCIAUX',4,0),(438,'ORGANISMES SOCIAUX, CHARGES A PAYER ET PRODUITS A RECEVOIR','ORGANISMES SOCIAUX, CHARGES A PAYER ET PRODUITS A RECEVOIR',4,0),(441,'ETAT, IMPOT SUR LES BENEFICES','ETAT, IMPOT SUR LES BENEFICES',4,0),(442,'ETAT, AUTRES IMPOTS ET TAXES','ETAT, AUTRES IMPOTS ET TAXES',4,0),(443,'ETAT, T.V.A. FACTUREE','ETAT, T.V.A. FACTUREE',4,0),(444,'ETAT, T.V.A. DUE OU CREDIT DE T.V.A.','ETAT, T.V.A. DUE OU CREDIT DE T.V.A.',4,0),(445,'ETAT, T.V.A. RECUPERABLE','ETAT, T.V.A. RECUPERABLE',4,0),(446,'ETAT, AUTRES TAXES SUR LE CHIFFRE D\'AFFAIRES','ETAT, AUTRES TAXES SUR LE CHIFFRE D\'AFFAIRES',4,0),(447,'ETAT, IMPOTS RETENUS A LA SOURCE','ETAT, IMPOTS RETENUS A LA SOURCE',4,0),(448,'ETAT, CHARGES A PAYER ET PRODUITS A RECEVOIR','ETAT, CHARGES A PAYER ET PRODUITS A RECEVOIR',4,0),(449,'ETAT, CREANCES ET DETTES DIVERSES','ETAT, CREANCES ET DETTES DIVERSES',4,0),(451,'OPERATIONS AVEC LES ORGANISMES AFRICAINS','OPERATIONS AVEC LES ORGANISMES AFRICAINS',4,0),(452,'OPERATIONS AVEC LES AUTRES ORGANISMES INTERNATIONAUX','OPERATIONS AVEC LES AUTRES ORGANISMES INTERNATIONAUX',4,0),(458,'ORGANISMES INTERNATIONAUX, FONDS DE DOTATION ET SUBVENTIONS A RECEVOIR','ORGANISMES INTERNATIONAUX, FONDS DE DOTATION ET SUBVENTIONS A RECEVOIR',4,0),(461,'ASSOCIES, OPERATIONS SUR LE CAPITAL','ASSOCIES, OPERATIONS SUR LE CAPITAL',4,0),(462,'ASSOCIES, COMPTES COURANTS','ASSOCIES, COMPTES COURANTS',4,0),(463,'ASSOCIES, OPERATIONS FAITES EN COMMUN','ASSOCIES, OPERATIONS FAITES EN COMMUN',4,0),(465,'ASSOCIES, DIVIDENDES A PAYER','ASSOCIES, DIVIDENDES A PAYER',4,0),(466,'GROUPE, COMPTES COURANTS','GROUPE, COMPTES COURANTS',4,0),(467,'ACTIONNAIRES, RESTANT DU DUR CAPITAL APPELE','ACTIONNAIRES, RESTANT DU DUR CAPITAL APPELE',4,0),(471,'COMPTES D\'ATTENTE','COMPTES D\'ATTENTE',4,0),(472,'VERSEMENTS RESTANT A EFFECTUER SUR TITRES NON LIBERES','VERSEMENTS RESTANT A EFFECTUER SUR TITRES NON LIBERES',4,0),(474,'REPARTITION PERIODIQUE DES CHARGES ET DES PRODUITS','REPARTITION PERIODIQUE DES CHARGES ET DES PRODUITS',4,0),(475,'CREANCES SUR TRAVAUX NON ENCORE FACTURABLES','CREANCES SUR TRAVAUX NON ENCORE FACTURABLES',4,0),(476,'CHARGES CONSTATEES D\'AVANCE','CHARGES CONSTATEES D\'AVANCE',4,0),(477,'PRODUITS CONSTATES D\'AVANCE','PRODUITS CONSTATES D\'AVANCE',4,0),(478,'ECARTS DE CONVERSION - ACTIF','ECARTS DE CONVERSION - ACTIF',4,0),(479,'ECARTS DE CONVERSION - PASSIF','ECARTS DE CONVERSION - PASSIF',4,0),(481,'FOURNISSEURS D\'INVESTISSEMENTS','FOURNISSEURS D\'INVESTISSEMENTS',4,0),(482,'FOURNISSEURS D\'INVESTISSEMENTS, EFFETS A PAYER','FOURNISSEURS D\'INVESTISSEMENTS, EFFETS A PAYER',4,0),(483,'DETTES SUR ACQUISITION DE TITRES DE PLACEMENT','DETTES SUR ACQUISITION DE TITRES DE PLACEMENT',4,0),(484,'AUTRES DETTES HORS ACTIVITES ORDINAIRES (H.A.O.)','AUTRES DETTES HORS ACTIVITES ORDINAIRES (H.A.O.)',4,0),(485,'CREANCES SUR CESSIONS D\'IMMOBILISATIONS','CREANCES SUR CESSIONS D\'IMMOBILISATIONS',4,0),(486,'CREANCES SUR CESSIONS DE TITRES DE PLACEMENT','CREANCES SUR CESSIONS DE TITRES DE PLACEMENT',4,0),(488,'AUTRES CREANCES HORS ACTIVITES ORDINAIRES (H.A.O.)','AUTRES CREANCES HORS ACTIVITES ORDINAIRES (H.A.O.)',4,0),(490,'DEPRECIATIONS DES COMPTES FOURNISSEURS','DEPRECIATIONS DES COMPTES FOURNISSEURS',4,0),(491,'DEPRECIATIONS DES COMPTES CLIENTS','DEPRECIATIONS DES COMPTES CLIENTS',4,0),(492,'DEPRECIATIONS DES COMPTES PERSONNEL','DEPRECIATIONS DES COMPTES PERSONNEL',4,0),(493,'DEPRECIATIONS DES COMPTES ORGANISMES SOCIAUX','DEPRECIATIONS DES COMPTES ORGANISMES SOCIAUX',4,0),(494,'DEPRECIATIONS DES COMPTES ETAT ET COLLECTIVITES PUBLIQUES','DEPRECIATIONS DES COMPTES ETAT ET COLLECTIVITES PUBLIQUES',4,0),(495,'DEPRECIATIONS DES COMPTES ORGANISMES INTERNATIONAUX','DEPRECIATIONS DES COMPTES ORGANISMES INTERNATIONAUX',4,0),(496,'DEPRECIATIONS DES COMPTES ASSOCIES ET GROUPE','DEPRECIATIONS DES COMPTES ASSOCIES ET GROUPE',4,0),(497,'DEPRECIATIONS DES COMPTES DEBITEURS DIVERS','DEPRECIATIONS DES COMPTES DEBITEURS DIVERS',4,0),(498,'DEPRECIATIONS DES COMPTES DE CREANCES H.A.O.','DEPRECIATIONS DES COMPTES DE CREANCES H.A.O.',4,0),(499,'RISQUES PROVISIONNNES','RISQUES PROVISIONNNES',4,0),(501,'TITRES DU TRESOR ET BONS DE CAISSE A COURT TERME','TITRES DU TRESOR ET BONS DE CAISSE A COURT TERME',5,0),(502,'ACTIONS','ACTIONS',5,0),(503,'OBLIGATIONS','OBLIGATIONS',5,0),(504,'BONS DE SOUSCRIPTION','BONS DE SOUSCRIPTION',5,0),(505,'TITRES NEGOCIABLES HORS REGION','TITRES NEGOCIABLES HORS REGION',5,0),(506,'INTERETS COURUS','INTERETS COURUS',5,0),(508,'AUTRES VALEURS ASSIMILEES','AUTRES VALEURS ASSIMILEES',5,0),(511,'EFFETS A ENCAISSER','EFFETS A ENCAISSER',5,0),(512,'EFFETS A L\'ENCAISSEMENT','EFFETS A L\'ENCAISSEMENT',5,0),(513,'CHEQUES A ENCAISSER','CHEQUES A ENCAISSER',5,0),(514,'CHEQUES A L\'ENCAISSEMENT','CHEQUES A L\'ENCAISSEMENT',5,0),(515,'CARTES DE CREDIT A ENCAISSER','CARTES DE CREDIT A ENCAISSER',5,0),(518,'AUTRES VALEURS A L\'ENCAISSEMENT','AUTRES VALEURS A L\'ENCAISSEMENT',5,0),(521,'BANQUES LOCALES','BANQUES LOCALES',5,0),(522,'BANQUES AUTRES ETATS REGION','BANQUES AUTRES ETATS REGION',5,0),(523,'BANQUES AUTRES ETATS ZONE MONETAIRE','BANQUES AUTRES ETATS ZONE MONETAIRE',5,0),(524,'BANQUES HORS ZONE MONETAIRE','BANQUES HORS ZONE MONETAIRE',5,0),(526,'BANQUES, INTERETS COURUS','BANQUES, INTERETS COURUS',5,0),(531,'CHEQUES POSTAUX','CHEQUES POSTAUX',5,0),(532,'TRESOR','TRESOR',5,0),(533,'SOCIETES DE GESTION ET D\'INTERMEDIATION (S.G.I.)','SOCIETES DE GESTION ET D\'INTERMEDIATION (S.G.I.)',5,0),(536,'ETABLISSEMENTS FINANCIERS, INTERETS COURUS','ETABLISSEMENTS FINANCIERS, INTERETS COURUS',5,0),(538,'AUTRES ORGANISMES FINANCIERS','AUTRES ORGANISMES FINANCIERS',5,0),(541,'OPTIONS DE TAUX D\'INTER√äT','OPTIONS DE TAUX D\'INTER√äT',5,0),(542,'OPTIONS DE TAUX DE CHANGE','OPTIONS DE TAUX DE CHANGE',5,0),(543,'OPTIONS DE TAUX BOURSIERS','OPTIONS DE TAUX BOURSIERS',5,0),(544,'INSTRUMENTS DE MARCHES A TERME','INSTRUMENTS DE MARCHES A TERME',5,0),(545,'AVOIRS D\'OR ET AUTRES METAUX PRECIEUX','AVOIRS D\'OR ET AUTRES METAUX PRECIEUX',5,0),(561,'CREDITS DE TRESORERIE','CREDITS DE TRESORERIE',5,0),(564,'ESCOMPTE DE CREDITS DE CAMPAGNE','ESCOMPTE DE CREDITS DE CAMPAGNE',5,0),(565,'ESCOMPTE DE CREDITS ORDINAIRES','ESCOMPTE DE CREDITS ORDINAIRES',5,0),(566,'BANQUES, CREDITS DE TRESORERIE, INTERETS COURUS','BANQUES, CREDITS DE TRESORERIE, INTERETS COURUS',5,0),(571,'CAISSE SIEGE SOCIAL','CAISSE SIEGE SOCIAL',5,0),(572,'CAISSE SUCCURSALE A','CAISSE SUCCURSALE A',5,0),(573,'CAISSE SUCCURSALE B','CAISSE SUCCURSALE B',5,0),(581,'REGIES D\'AVANCE','REGIES D\'AVANCE',5,0),(582,'ACCREDITIFS','ACCREDITIFS',5,0),(585,'VIREMENTS DE FONDS','VIREMENTS DE FONDS',5,0),(588,'AUTRES VIREMENTS INTERNES','AUTRES VIREMENTS INTERNES',5,0),(590,'DEPRECIATIONS DES TITRES DE PLACEMENT','DEPRECIATIONS DES TITRES DE PLACEMENT',5,0),(591,'DEPRECIATIONS DES TITRES ET VALEURS A ENCAISSER','DEPRECIATIONS DES TITRES ET VALEURS A ENCAISSER',5,0),(592,'DEPRECIATIONS DES COMPTES BANQUES','DEPRECIATIONS DES COMPTES BANQUES',5,0),(593,'DEPRECIATIONS DES COMPTES ETABLISSEMENTS FINANCIERS ET ASSIMILES','DEPRECIATIONS DES COMPTES ETABLISSEMENTS FINANCIERS ET ASSIMILES',5,0),(594,'DEPRECIATIONS DES COMPTES D\'INSTRUMENTS DE TRESORERIE','DEPRECIATIONS DES COMPTES D\'INSTRUMENTS DE TRESORERIE',5,0),(599,'RISQUES PROVISIONNES A CARACTERE FINANCIER','RISQUES PROVISIONNES A CARACTERE FINANCIER',5,0),(601,'ACHATS DE MARCHANDISES','ACHATS DE MARCHANDISES',6,0),(602,'ACHATS DE MATIERES PREMIERES ET FOURNITURES LIEES','ACHATS DE MATIERES PREMIERES ET FOURNITURES LIEES',6,0),(603,'VARIATIONS DES STOCKS DE BIENS ACHETES','VARIATIONS DES STOCKS DE BIENS ACHETES',6,0),(604,'ACHATS STOCKES DE MATIERES ET FOURNITURES CONSOMMABLES','ACHATS STOCKES DE MATIERES ET FOURNITURES CONSOMMABLES',6,0),(605,'AUTRES ACHATS','AUTRES ACHATS',6,0),(608,'ACHATS D\'EMBALLAGES','ACHATS D\'EMBALLAGES',6,0),(611,'TRANSPORTS SUR ACHAT','TRANSPORTS SUR ACHAT',6,0),(612,'TRANSPORTS SUR VENTES ','TRANSPORTS SUR VENTES ',6,0),(613,'TRANSPORTS POUR LE COMPTE DE TIERS','TRANSPORTS POUR LE COMPTE DE TIERS',6,0),(614,'TRANSPORTS DU PERSONNEL','TRANSPORTS DU PERSONNEL',6,0),(616,'TRANSPORTS DE PLIS','TRANSPORTS DE PLIS',6,0),(618,'AUTRES FRAIS DE TRANSPORT','AUTRES FRAIS DE TRANSPORT',6,0),(621,'SOUS-TRAITANCE GENERALE','SOUS-TRAITANCE GENERALE',6,0),(622,'LOCATIONS ET CHARGES LOCATIVES','LOCATIONS ET CHARGES LOCATIVES',6,0),(623,'REDEVANCES DE CREDIT-BAIL ET CONTRATS ASSIMILES','REDEVANCES DE CREDIT-BAIL ET CONTRATS ASSIMILES',6,0),(624,'ENTRETIEN, REPARATIONS ET MAINTENANCE','ENTRETIEN, REPARATIONS ET MAINTENANCE',6,0),(625,'PRIMES D\'ASSURANCE','PRIMES D\'ASSURANCE',6,0),(626,'ETUDES, RECHERCHES ET DOCUMENTATION','ETUDES, RECHERCHES ET DOCUMENTATION',6,0),(627,'PUBLICITE, PUBLICATIONS, RELATIONS PUBLIQUES','PUBLICITE, PUBLICATIONS, RELATIONS PUBLIQUES',6,0),(628,'FRAIS DE TELECOMMUNICATIONS','FRAIS DE TELECOMMUNICATIONS',6,0),(631,'FRAIS BANCAIRES','FRAIS BANCAIRES',6,0),(632,'REMUNERATIONS D\'INTERMEDIAIRES ET DE CONSEILS','REMUNERATIONS D\'INTERMEDIAIRES ET DE CONSEILS',6,0),(633,'FRAIS DE FORMATION DU PERSONNEL','FRAIS DE FORMATION DU PERSONNEL',6,0),(634,'REDEVANCES POUR BREVETS, LICENCES, LOGICIELS ET DROITS SIMILAIRES','REDEVANCES POUR BREVETS, LICENCES, LOGICIELS ET DROITS SIMILAIRES',6,0),(635,'COTISATIONS','COTISATIONS',6,0),(637,'REMUNERATIONS DE PERSONNEL EXTERIEUR A L\'ENTREPRISE','REMUNERATIONS DE PERSONNEL EXTERIEUR A L\'ENTREPRISE',6,0),(638,'AUTRES CHARGES EXTERNES','AUTRES CHARGES EXTERNES',6,0),(641,'IMPOTS ET TAXES DIRECTS','IMPOTS ET TAXES DIRECTS',6,0),(645,'IMPOTS ET TAXES INDIRECTS','IMPOTS ET TAXES INDIRECTS',6,0),(646,'DROITS D\'ENREGISTREMENT','DROITS D\'ENREGISTREMENT',6,0),(647,'PENALITES ET AMENDES FISCALES','PENALITES ET AMENDES FISCALES',6,0),(648,'AUTRES IMPOTS ET TAXES','AUTRES IMPOTS ET TAXES',6,0),(651,'PERTES SUR CREANCES CLIENTS ET AUTRES DEBITEURS','PERTES SUR CREANCES CLIENTS ET AUTRES DEBITEURS',6,0),(652,'QUOTE-PART DE RESULTAT SUR OPERATIONS FAITES EN COMMUN','QUOTE-PART DE RESULTAT SUR OPERATIONS FAITES EN COMMUN',6,0),(653,'QUOTE-PART DE RESULTAT ANNULEE SUR EXECUTION PARTIELLE DE CONTRATS PLURI-EXERCICES ','QUOTE-PART DE RESULTAT ANNULEE SUR EXECUTION PARTIELLE DE CONTRATS PLURI-EXERCICES ',6,0),(654,'VALEUR COMPTABLE DES CESSIONS COURANTES D\'IMMOBILISATIONS','VALEUR COMPTABLE DES CESSIONS COURANTES D\'IMMOBILISATIONS',6,0),(658,'CHARGES DIVERSES','CHARGES DIVERSES',6,0),(659,'CHARGES PROVISIONNEES D\'EXPLOITATION','CHARGES PROVISIONNEES D\'EXPLOITATION',6,0),(661,'REMUNERATIONS DIRECTES VERSEES AU PERSONNEL NATIONAL','REMUNERATIONS DIRECTES VERSEES AU PERSONNEL NATIONAL',6,0),(662,'REMUNERATIONS DIRECTES VERSEES AU PERSONNEL NON NATIONAL','REMUNERATIONS DIRECTES VERSEES AU PERSONNEL NON NATIONAL',6,0),(663,'INDEMNITES FORFAITAIRES VERSEES AU PERSONNEL','INDEMNITES FORFAITAIRES VERSEES AU PERSONNEL',6,0),(664,'CHARGES SOCIALES','CHARGES SOCIALES',6,0),(666,'REMUNERATION ET CHARGES SOCIALES DE L\'EXPLOITANT INDIVIDUEL','REMUNERATION ET CHARGES SOCIALES DE L\'EXPLOITANT INDIVIDUEL',6,0),(667,'REMUNERATION TRANSFEREE DE PERSONNEL EXTERIEUR','REMUNERATION TRANSFEREE DE PERSONNEL EXTERIEUR',6,0),(668,'AUTRES CHARGES SOCIALES','AUTRES CHARGES SOCIALES',6,0),(671,'INTERETS DES EMPRUNTS','INTERETS DES EMPRUNTS',6,0),(672,'INTERETS DANS LOYERS DE CREDIT-BAIL ET CONTRATS ASSIMILES','INTERETS DANS LOYERS DE CREDIT-BAIL ET CONTRATS ASSIMILES',6,0),(673,'ESCOMPTES ACCORDES','ESCOMPTES ACCORDES',6,0),(674,'AUTRES INTERETS','AUTRES INTERETS',6,0),(675,'ESCOMPTES DES EFFETS DE COMMERCE','ESCOMPTES DES EFFETS DE COMMERCE',6,0),(676,'PERTES DE CHANGE','PERTES DE CHANGE',6,0),(677,'PERTES SUR CESSIONS DE TITRES DE PLACEMENT','PERTES SUR CESSIONS DE TITRES DE PLACEMENT',6,0),(678,'PERTES SUR RISQUES FINANCIERS','PERTES SUR RISQUES FINANCIERS',6,0),(679,'CHARGES PROVISIONNEES FINANCIERES','CHARGES PROVISIONNEES FINANCIERES',6,0),(681,'DOTATIONS AUX AMORTISSEMENTS D\'EXPLOITATION','DOTATIONS AUX AMORTISSEMENTS D\'EXPLOITATION',6,0),(687,'DOTATIONS AUX AMORTISSEMENTS A CARACTERE FINANCIER','DOTATIONS AUX AMORTISSEMENTS A CARACTERE FINANCIER',6,0),(691,'DOTATIONS AUX PROVISIONS D\'EXPLOITATION','DOTATIONS AUX PROVISIONS D\'EXPLOITATION',6,0),(697,'DOTATIONS AUX PROVISIONS FINANCIERES','DOTATIONS AUX PROVISIONS FINANCIERES',6,0),(701,'VENTES DE MARCHANDISES','VENTES DE MARCHANDISES',7,0),(702,'VENTES DE PRODUITS FINIS','Vente produit restaurant',7,1),(703,'VENTES DE PRODUITS INTERMEDIAIRES','VENTES DE PRODUITS INTERMEDIAIRES',7,0),(704,'VENTES DE PRODUITS RESIDUELS ','VENTES DE PRODUITS RESIDUELS ',7,0),(705,'TRAVAUX FACTURES','TRAVAUX FACTURES',7,0),(706,'SERVICES VENDUS','SERVICES VENDUS',7,0),(707,'PRODUITS ACCESSOIRES','PRODUITS ACCESSOIRES',7,0),(711,'SUR PRODUITS A L\'EXPORTATION','SUR PRODUITS A L\'EXPORTATION',7,0),(712,'SUR PRODUITS A L\'IMPORTATION','SUR PRODUITS A L\'IMPORTATION',7,0),(713,'SUR PRODUITS DE PEREQUATION','SUR PRODUITS DE PEREQUATION',7,0),(718,'AUTRES SUBVENTIONS D\'EXPLOITATION','AUTRES SUBVENTIONS D\'EXPLOITATION',7,0),(721,'IMMOBILISATIONS INCORPORELLES','IMMOBILISATIONS INCORPORELLES',7,0),(722,'IMMOBILISATIONS CORPORELLES','IMMOBILISATIONS CORPORELLES',7,0),(726,'IMMOBILISATIONS FINANCIERES','IMMOBILISATIONS FINANCIERES',7,0),(734,'VARIATIONS DES STOCKS DE PRODUITS EN COURS','VARIATIONS DES STOCKS DE PRODUITS EN COURS',7,0),(735,'VARIATIONS DES EN-COURS DE SERVICES','VARIATIONS DES EN-COURS DE SERVICES',7,0),(736,'VARIATIONS DES STOCKS DE PRODUITS FINIS','VARIATIONS DES STOCKS DE PRODUITS FINIS',7,0),(737,'VARIATIONS DES STOCKS DE PRODUITS INTERMEDIAIRES ET RESIDUELS','VARIATIONS DES STOCKS DE PRODUITS INTERMEDIAIRES ET RESIDUELS',7,0),(752,'QUOTE-PART DE RESULTAT SUR OPERATIONS FAITES EN COMMUN','QUOTE-PART DE RESULTAT SUR OPERATIONS FAITES EN COMMUN',7,0),(753,'QUOTE-PART DE RESULTAT SUR EXECUTION PARTIELLE DE CONTRATS PLURI-EXERCICES','QUOTE-PART DE RESULTAT SUR EXECUTION PARTIELLE DE CONTRATS PLURI-EXERCICES',7,0),(754,'PRODUITS DES CESSIONS COURANTES D\'IMMOBILISATIONS','PRODUITS DES CESSIONS COURANTES D\'IMMOBILISATIONS',7,0),(758,'PRODUITS DIVERS','PRODUITS DIVERS',7,0),(759,'REPRISES DE CHARGES PROVISIONNEES D\'EXPLOITATION','REPRISES DE CHARGES PROVISIONNEES D\'EXPLOITATION',7,0),(771,'INTERETS DE PRETS','INTERETS DE PRETS',7,0),(772,'REVENUS DE PARTICIPATIONS ','REVENUS DE PARTICIPATIONS ',7,0),(773,'ESCOMPTES OBTENUS','ESCOMPTES OBTENUS',7,0),(774,'REVENUS DE TITRES DE PLACEMENT','REVENUS DE TITRES DE PLACEMENT',7,0),(776,'GAINS DE CHANGE','GAINS DE CHANGE',7,0),(777,'GAINS SUR CESSIONS DE TITRES DE PLACEMENT','GAINS SUR CESSIONS DE TITRES DE PLACEMENT',7,0),(778,'GAINS SUR RISQUES FINANCIERS','GAINS SUR RISQUES FINANCIERS',7,0),(779,'REPRISES DE CHARGES PROVISIONNEES FINANCIERES','REPRISES DE CHARGES PROVISIONNEES FINANCIERES',7,0),(781,'TRANSFERTS DE CHARGES D\'EXPLOITATION','TRANSFERTS DE CHARGES D\'EXPLOITATION',7,0),(787,'TRANSFERTS DE CHARGES FINANCIERES','TRANSFERTS DE CHARGES FINANCIERES',7,0),(791,'REPRISES DE PROVISIONS D\'EXPLOITATION','REPRISES DE PROVISIONS D\'EXPLOITATION',7,0),(797,'REPRISES DE PROVISIONS FINANCIERES','REPRISES DE PROVISIONS FINANCIERES',7,0),(798,'REPRISES D\'AMORTISSMENTS','REPRISES D\'AMORTISSMENTS',7,0),(811,'IMMOBILISATIONS INCORPORELLES','IMMOBILISATIONS INCORPORELLES',8,0),(812,'IMMOBILISATIONS CORPORELLES','IMMOBILISATIONS CORPORELLES',8,0),(816,'IMMOBILISATIONS FINANCIERES','IMMOBILISATIONS FINANCIERES',8,0),(821,'IMMOBILISATIONS INCORPORELLES','IMMOBILISATIONS INCORPORELLES',8,0),(822,'IMMOBILISATIONS CORPORELLES','IMMOBILISATIONS CORPORELLES',8,0),(826,'IMMOBILISATIONS FINANCIERES','IMMOBILISATIONS FINANCIERES',8,0),(831,'CHARGES H.A.O. CONSTATEES','CHARGES H.A.O. CONSTATEES',8,0),(834,'PERTES SUR CREANCES H.A.O.','PERTES SUR CREANCES H.A.O.',8,0),(835,'DONS ET LIBERALITES ACCORDES','DONS ET LIBERALITES ACCORDES',8,0),(836,'ABANDONS DE CREANCES CONSENTIS','ABANDONS DE CREANCES CONSENTIS',8,0),(839,'CHARGES PROVISIONNEES H.A.O.','CHARGES PROVISIONNEES H.A.O.',8,0),(841,'PRODUITS H.A.O. CONSTATES','PRODUITS H.A.O. CONSTATES',8,0),(845,'DONS ET LIBERALITES OBTENUS','DONS ET LIBERALITES OBTENUS',8,0),(846,'ABANDONS DE CREANCES OBTENUS','ABANDONS DE CREANCES OBTENUS',8,0),(848,'TRANSFERTS DE CHARGES H.A.O.','TRANSFERTS DE CHARGES H.A.O.',8,0),(849,'REPRISES DES CHARGES PROVISIONNEES H.A.O.','REPRISES DES CHARGES PROVISIONNEES H.A.O.',8,0),(851,'DOTATIONS AUX PROVISIONS REGLEMENTEES','DOTATIONS AUX PROVISIONS REGLEMENTEES',8,0),(852,'DOTATIONS AUX AMORTISSEMENTS H.A.O.','DOTATIONS AUX AMORTISSEMENTS H.A.O.',8,0),(853,'DOTATIONS AUX PROVISIONS POUR DEPRECIATION H.A.O.','DOTATIONS AUX PROVISIONS POUR DEPRECIATION H.A.O.',8,0),(854,'DOTATIONS AUX PROVISIONS POUR RISQUES ET CHARGES H.A.O.','DOTATIONS AUX PROVISIONS POUR RISQUES ET CHARGES H.A.O.',8,0),(858,'AUTRES DOTATIONS H.A.O.','AUTRES DOTATIONS H.A.O.',8,0),(861,'REPRISES DE PROVISIONS REGLEMENTEES','REPRISES DE PROVISIONS REGLEMENTEES',8,0),(862,'REPRISES D\'AMORTISSEMENTS','REPRISES D\'AMORTISSEMENTS',8,0),(863,'REPRISES DE PROVISIONS POUR DEPRECIATION H.A.O.','REPRISES DE PROVISIONS POUR DEPRECIATION H.A.O.',8,0),(864,'REPRISES DE PROVISIONS POUR RISQUES ET CHARGES H.A.O.','REPRISES DE PROVISIONS POUR RISQUES ET CHARGES H.A.O.',8,0),(865,'REPRISES DE SUBVENTIONS D\'INVESTISSEMENT','REPRISES DE SUBVENTIONS D\'INVESTISSEMENT',8,0),(868,'AUTRES REPRISES H.A.O.','AUTRES REPRISES H.A.O.',8,0),(871,'PARTICIPATION LEGALE AUX BENEFICES ','PARTICIPATION LEGALE AUX BENEFICES ',8,0),(874,'PARTICIPATION CONTRACTUELLE AUX BENEFICES','PARTICIPATION CONTRACTUELLE AUX BENEFICES',8,0),(878,'AUTRES PARTICIPATIONS','AUTRES PARTICIPATIONS',8,0),(881,'ETAT','ETAT',8,0),(884,'COLLECTIVITES PUBLIQUES','COLLECTIVITES PUBLIQUES',8,0),(886,'GROUPE','GROUPE',8,0),(888,'AUTRES','AUTRES',8,0),(891,'IMPOTS SUR LES BENEFICES DE L\'EXERCICE','IMPOTS SUR LES BENEFICES DE L\'EXERCICE',8,0),(892,'RAPPEL D\'IMPOTS SUR RESULTATS ANTERIEURS','RAPPEL D\'IMPOTS SUR RESULTATS ANTERIEURS',8,0),(895,'IMPOT MINIMUM FORFAITAIRE (I.M.F.)','IMPOT MINIMUM FORFAITAIRE (I.M.F.)',8,0),(899,'DEGREVEMENTS ET ANNULATIONS D\'IMPOTS SUR RESULTATS ANTERIEURS','DEGREVEMENTS ET ANNULATIONS D\'IMPOTS SUR RESULTATS ANTERIEURS',8,0),(901,'ENGAGEMENTS DE FINANCEMENT OBTENUS','ENGAGEMENTS DE FINANCEMENT OBTENUS',9,0),(902,'ENGAGEMENTS DE GARANTIE OBTENUS','ENGAGEMENTS DE GARANTIE OBTENUS',9,0),(903,'ENGAGEMENTS RECIPROQUES','ENGAGEMENTS RECIPROQUES',9,0),(904,'AUTRES ENGAGEMENTS OBTENUS','AUTRES ENGAGEMENTS OBTENUS',9,0),(905,'ENGAGEMENTS DE FINANCEMENT ACCORDES','ENGAGEMENTS DE FINANCEMENT ACCORDES',9,0),(906,'ENGAGEMENTS DE GARANTIE ACCORDES','ENGAGEMENTS DE GARANTIE ACCORDES',9,0),(907,'ENGAGEMENTS RECIPROQUES','ENGAGEMENTS RECIPROQUES',9,0),(908,'AUTRES ENGAGEMENTS ACCORDES','AUTRES ENGAGEMENTS ACCORDES',9,0),(1011,'Capital souscrit, non appel√©','Capital souscrit, non appel√©',1,0),(1012,'Capital souscrit, appel√©, non vers√©','Capital souscrit, appel√©, non vers√©',1,0),(1013,'Capital souscrit, appel√©, vers√©, non amorti','Capital souscrit, appel√©, vers√©, non amorti',1,0),(1014,'Capital souscrit, appel√©, vers√©, amorti','Capital souscrit, appel√©, vers√©, amorti',1,0),(1018,'Capital souscrit soumis √† des conditions particuli√®res','Capital souscrit soumis √† des conditions particuli√®res',1,0),(1021,'Dotation initiale','Dotation initiale',1,0),(1022,'Dotations compl√©mentaires','Dotations compl√©mentaires',1,0),(1028,'Autres dotations','Autres dotations',1,0),(1041,'Apports temporaires','Apports temporaires',1,0),(1042,'Op√©rations courantes','Op√©rations courantes',1,0),(1043,'R√©mun√©rations, imp√¥ts et autres charges personnelles','R√©mun√©rations, imp√¥ts et autres charges personnelles',1,0),(1047,'Pr√©l√®vements d\'autoconsommation','Pr√©l√®vements d\'autoconsommation',1,0),(1048,'Autres pr√©l√®vements','Autres pr√©l√®vements',1,0),(1051,'Primes d\'√©mission','Primes d\'√©mission',1,0),(1052,'Primes d\'apport','Primes d\'apport',1,0),(1053,'Primes de fusion','Primes de fusion',1,0),(1054,'Primes de conversion','Primes de conversion',1,0),(1058,'Autres primes','Autres primes',1,0),(1061,'Ecarts de r√©√©valuation l√©gale','Ecarts de r√©√©valuation l√©gale',1,0),(1062,'Ecarts de r√©√©valuation libre','Ecarts de r√©√©valuation libre',1,0),(1131,'R√©serves de plus-values nettes √† long terme','R√©serves de plus-values nettes √† long terme',1,0),(1133,'R√©serves cons√©cutives √† l\'octroi de subventions d\'investissement','R√©serves cons√©cutives √† l\'octroi de subventions d\'investissement',1,0),(1138,'Autres r√©serves r√©glement√©es','Autres r√©serves r√©glement√©es',1,0),(1181,'R√©serves facultatives','R√©serves facultatives',1,0),(1188,'R√©serves diverses','R√©serves diverses',1,0),(1291,'Perte nette √† reporter','Perte nette √† reporter',1,0),(1292,'Perte-Amortissements r√©put√©s diff√©r√©s','Perte-Amortissements r√©put√©s diff√©r√©s',1,0),(1301,'R√©sultat en instance d\'affectation : B√©n√©fice','R√©sultat en instance d\'affectation : B√©n√©fice',1,0),(1309,'R√©sultat en instance d\'affectation : Perte','R√©sultat en instance d\'affectation : Perte',1,0),(1321,'Marge brute sur marchandises','Marge brute sur marchandises',1,0),(1322,'Marge brute sur mati√®res','Marge brute sur mati√®res',1,0),(1411,'Etat','Etat',1,0),(1412,'R√©gions','R√©gions',1,0),(1413,'D√©partements','D√©partements',1,0),(1414,'Communes et collectivit√©s publiques d√©centralis√©es','Communes et collectivit√©s publiques d√©centralis√©es',1,0),(1415,'Entreprises publiques ou mixtes','Entreprises publiques ou mixtes',1,0),(1416,'Entreprises et organismes priv√©s','Entreprises et organismes priv√©s',1,0),(1417,'Organismes internationaux','Organismes internationaux',1,0),(1418,'Autres','Autres',1,0),(1531,'Fond National','Fond National',1,0),(1532,'Pr√©l√®vement pour le Budget','Pr√©l√®vement pour le Budget',1,0),(1551,'Reconstitution des gisements miniers et p√©troliers','Reconstitution des gisements miniers et p√©troliers',1,0),(1561,'Hausse de prix','Hausse de prix',1,0),(1562,'Fluctuation des cours','Fluctuation des cours',1,0),(1611,'Emprunts obligataires ordinaires','Emprunts obligataires ordinaires',1,0),(1612,'Emprunts obligatoires convertibles','Emprunts obligatoires convertibles',1,0),(1618,'Autres emprunts obligataires','Autres emprunts obligataires',1,0),(1651,'D√©p√¥ts','D√©p√¥ts',1,0),(1652,'Cautionnements','Cautionnements',1,0),(1661,'Int√©r√™ts courus sur emprunts obligataires','Int√©r√™ts courus sur emprunts obligataires',1,0),(1662,'Int√©r√™ts courus sur emprunts et dettes aupr√®s des √©tablissements de cr√©dit','Int√©r√™ts courus sur emprunts et dettes aupr√®s des √©tablissements de cr√©dit',1,0),(1663,'Int√©r√™ts courus sur avances re√ßues de l\'Etat','Int√©r√™ts courus sur avances re√ßues de l\'Etat',1,0),(1664,'Int√©r√™ts courus sur avances re√ßues et comptes courants bloqu√©s','Int√©r√™ts courus sur avances re√ßues et comptes courants bloqu√©s',1,0),(1665,'Int√©r√™ts courus sur d√©p√¥ts et cautionnements rec√ßus','Int√©r√™ts courus sur d√©p√¥ts et cautionnements rec√ßus',1,0),(1667,'Int√©r√™ts courus sur avances assorties de conditions particuli√®res','Int√©r√™ts courus sur avances assorties de conditions particuli√®res',1,0),(1668,'Int√©r√™ts courus sur autres emprunts et dettes','Int√©r√™ts courus sur autres emprunts et dettes',1,0),(1671,'Avances bloqu√©es pour augmentation du capital','Avances bloqu√©es pour augmentation du capital',1,0),(1672,'Avances conditionn√©es par l\'Etat','Avances conditionn√©es par l\'Etat',1,0),(1673,'Avances conditionn√©es par les autres organismes africains','Avances conditionn√©es par les autres organismes africains',1,0),(1674,'Avances conditionn√©es par les organismes internationaux','Avances conditionn√©es par les organismes internationaux',1,0),(1676,'Droits du conc√©dant exigibles en nature','Droits du conc√©dant exigibles en nature',1,0),(1681,'Rentes viag√®res capitalis√©es','Rentes viag√®res capitalis√©es',1,0),(1682,'Billets de fonds','Billets de fonds',1,0),(1683,'Dettes cons√©cutives √† des titres emprunt√©s','Dettes cons√©cutives √† des titres emprunt√©s',1,0),(1684,'Dettes du conc√©dant exigibles en nature','Dettes du conc√©dant exigibles en nature',1,0),(1685,'Emprunts participatifs','Emprunts participatifs',1,0),(1686,'Participation des travailleurs aux b√©n√©fices','Participation des travailleurs aux b√©n√©fices',1,0),(1762,'Int√©r√™ts courus sur emprunts √©quivalents de cr√©dit - bail immobilier','Int√©r√™ts courus sur emprunts √©quivalents de cr√©dit - bail immobilier',1,0),(1763,'Int√©r√™ts courus sur emprunts √©quivalents de cr√©dit - bail mobilier','Int√©r√™ts courus sur emprunts √©quivalents de cr√©dit - bail mobilier',1,0),(1768,'Int√©r√™ts courus sur emprunts √©quivalents d\'autres contrats','Int√©r√™ts courus sur emprunts √©quivalents d\'autres contrats',1,0),(1811,'Dettes li√©es √† des participations (groupe)','Dettes li√©es √† des participations (groupe)',1,0),(1812,'Dettes li√©es √† des participations (hors groupe)','Dettes li√©es √† des participations (hors groupe)',1,0),(1971,'Provisions pour grosses r√©parations','Provisions pour grosses r√©parations',1,0),(1981,'Provisions pour amendes et p√©nalit√©s','Provisions pour amendes et p√©nalit√©s',1,0),(1982,'Provisions pour renouvellement des immobilisations (entreprises concessionnaires)','Provisions pour renouvellement des immobilisations (entreprises concessionnaires)',1,0),(1983,'Provisions de propre assureur','Provisions de propre assureur',1,0),(1988,'Autres provisions financi√®res pour risques et charges','Autres provisions financi√®res pour risques et charges',1,0),(2011,'Frais de constitution','Frais de constitution',2,0),(2012,'Frais de prospection','Frais de prospection',2,0),(2013,'Frais de publicit√© et de lancement','Frais de publicit√© et de lancement',2,0),(2014,'Frais de fonctionnement ant√©rieurs au d√©marrage','Frais de fonctionnement ant√©rieurs au d√©marrage',2,0),(2015,'Frais de modification du capital (fusions, scissions, transformations)','Frais de modification du capital (fusions, scissions, transformations)',2,0),(2016,'Frais d\'entr√©e √† la Bourse','Frais d\'entr√©e √† la Bourse',2,0),(2017,'Frais de restructuration','Frais de restructuration',2,0),(2018,'Frais divers d\'√©tablissement','Frais divers d\'√©tablissement',2,0),(2021,'Charges diff√©r√©es','Charges diff√©r√©es',2,0),(2022,'Frais d\'acquisition d\'immobilisations','Frais d\'acquisition d\'immobilisations',2,0),(2026,'Frais d\'√©mission des emprunts','Frais d\'√©mission des emprunts',2,0),(2028,'Charges √† √©taler','Charges √† √©taler',2,0),(2061,'Obligations ordinaires','Obligations ordinaires',2,0),(2062,'Obligations convertibles','Obligations convertibles',2,0),(2068,'Autres emprunts obligataires','Autres emprunts obligataires',2,0),(2191,'Frais de recherche et de d√©veloppement','Frais de recherche et de d√©veloppement',2,0),(2193,'Logiciels','Logiciels',2,0),(2198,'Autres droits et valeurs incorporels','Autres droits et valeurs incorporels',2,0),(2211,'Terrains d\'exploitation agricole','Terrains d\'exploitation agricole',2,0),(2212,'Terrains d\'exploitation foresti√®re','Terrains d\'exploitation foresti√®re',2,0),(2218,'Autres terrains','Autres terrains',2,0),(2221,'Terrains √† b√¢tir','Terrains √† b√¢tir',2,0),(2228,'Autres terrains nus','Autres terrains nus',2,0),(2231,'pour b√¢timents industriels et agricoles','pour b√¢timents industriels et agricoles',2,0),(2232,'pour b√¢timents administratifs et commerciaux','pour b√¢timents administratifs et commerciaux',2,0),(2234,'pour b√¢timents affect√©s aux autres op√©rations professionnelles','pour b√¢timents affect√©s aux autres op√©rations professionnelles',2,0),(2235,'pour b√¢timents affect√©s aux autres op√©rations non professionnelles','pour b√¢timents affect√©s aux autres op√©rations non professionnelles',2,0),(2238,'Autres terrains b√¢tis','Autres terrains b√¢tis',2,0),(2241,'Plantation d\'arbres et d\'arbustes','Plantation d\'arbres et d\'arbustes',2,0),(2248,'Autres travaux','Autres travaux',2,0),(2251,'Carri√®res','Carri√®res',2,0),(2261,'Parkings','Parkings',2,0),(2281,'Terrains des immeubles de rapport','Terrains des immeubles de rapport',2,0),(2285,'Terrains des logements affect√©s au personnel','Terrains des logements affect√©s au personnel',2,0),(2288,'Autres terrains','Autres terrains',2,0),(2291,'Terrains agricoles et forestiers','Terrains agricoles et forestiers',2,0),(2292,'Terrains nus','Terrains nus',2,0),(2295,'Terrains de gisement','Terrains de gisement',2,0),(2298,'Autres terrains','Autres terrains',2,0),(2311,'B√¢timens industriels','B√¢timens industriels',2,0),(2312,'B√¢timents agricoles','B√¢timents agricoles',2,0),(2313,'B√¢timents administratifs et commerciaux','B√¢timents administratifs et commerciaux',2,0),(2314,'B√¢timents affect√©s au logement du personnel','B√¢timents affect√©s au logement du personnel',2,0),(2315,'Immeubles de rapport','Immeubles de rapport',2,0),(2321,'B√¢timents industriels','B√¢timents industriels',2,0),(2322,'B√¢timents agricoles','B√¢timents agricoles',2,0),(2323,'B√¢timents administratifs et commerciaux','B√¢timents administratifs et commerciaux',2,0),(2324,'B√¢timents affect√©s au logement du personnel','B√¢timents affect√©s au logement du personnel',2,0),(2325,'Immeubles de rapport','Immeubles de rapport',2,0),(2331,'Voies de terre','Voies de terre',2,0),(2332,'Voies de fer','Voies de fer',2,0),(2333,'Voies d\'eau','Voies d\'eau',2,0),(2334,'Barrages, Digues','Barrages, Digues',2,0),(2335,'Pistes d\'a√©rodrome','Pistes d\'a√©rodrome',2,0),(2338,'Autres','Autres',2,0),(2341,'Installations complexes sp√©cialis√©es sur sol propre','Installations complexes sp√©cialis√©es sur sol propre',2,0),(2342,'Installations complexes sp√©cialis√©es sur sol d\'autrui','Installations complexes sp√©cialis√©es sur sol d\'autrui',2,0),(2343,'Installations √† caract√®re sp√©cifique sur sol propre','Installations √† caract√®re sp√©cifique sur sol propre',2,0),(2344,'Installations √† caract√®re sp√©cifique sur sol d\'autrui','Installations √† caract√®re sp√©cifique sur sol d\'autrui',2,0),(2351,'Installations g√©n√©rales','Installations g√©n√©rales',2,0),(2358,'Autres','Autres',2,0),(2411,'Mat√©riel industriel','Mat√©riel industriel',2,0),(2412,'Outillage industriel','Outillage industriel',2,0),(2413,'Mat√©riel commercial','Mat√©riel commercial',2,0),(2414,'Outillage commercial','Outillage commercial',2,0),(2421,'Mat√©riel agricole','Mat√©riel agricole',2,0),(2422,'Outillage agricole','Outillage agricole',2,0),(2441,'Mat√©riel de bureau','Mat√©riel de bureau',2,0),(2442,'Mat√©riel informatique','Mat√©riel informatique',2,0),(2443,'Mat√©riel bureautique','Mat√©riel bureautique',2,0),(2444,'Mobilier de bureau','Mobilier de bureau',2,0),(2446,'Mat√©riel et mobilier des immeubles de rapport','Mat√©riel et mobilier des immeubles de rapport',2,0),(2447,'Mat√©riel et mobilier des logements du personnel','Mat√©riel et mobilier des logements du personnel',2,0),(2451,'Mat√©riel automobile','Mat√©riel automobile',2,0),(2452,'Mat√©riel ferroviaire','Mat√©riel ferroviaire',2,0),(2453,'Mat√©riel fluvial, lagunaire','Mat√©riel fluvial, lagunaire',2,0),(2454,'Mat√©riel naval','Mat√©riel naval',2,0),(2455,'Mat√©riel a√©rien','Mat√©riel a√©rien',2,0),(2456,'Mat√©riel hippomobile','Mat√©riel hippomobile',2,0),(2458,'Autres (v√©lo, mobylette, moto)','Autres (v√©lo, mobylette, moto)',2,0),(2461,'Cheptel, animaux de trait','Cheptel, animaux de trait',2,0),(2462,'Cheptel, animaux reproducteurs','Cheptel, animaux reproducteurs',2,0),(2463,'Animaux de garde','Animaux de garde',2,0),(2465,'Plantations agricoles','Plantations agricoles',2,0),(2468,'Autres','Autres',2,0),(2481,'Collections et oeuvres d\'art','Collections et oeuvres d\'art',2,0),(2491,'Mat√©riel et outillage industriel et commercial','Mat√©riel et outillage industriel et commercial',2,0),(2492,'Mat√©riel et outillage agricole','Mat√©riel et outillage agricole',2,0),(2493,'Mat√©riel d\'emballage r√©cup√©rable et identifiable','Mat√©riel d\'emballage r√©cup√©rable et identifiable',2,0),(2494,'Mat√©riel de transport','Mat√©riel de transport',2,0),(2496,'Immobilisations animales et agricoles','Immobilisations animales et agricoles',2,0),(2497,'Agencements et am√©nagements du mat√©riel','Agencements et am√©nagements du mat√©riel',2,0),(2498,'Autres mat√©riels','Autres mat√©riels',2,0),(2711,'Pr√™ts participatifs','Pr√™ts participatifs',2,0),(2712,'Pr√™ts aux associ√©s','Pr√™ts aux associ√©s',2,0),(2713,'Billets de fonds','Billets de fonds',2,0),(2714,'Titres pr√™t√©s','Titres pr√™t√©s',2,0),(2721,'Pr√™ts immobiliers','Pr√™ts immobiliers',2,0),(2722,'Pr√™ts mobiliers et d\'installation','Pr√™ts mobiliers et d\'installation',2,0),(2728,'Autres pr√™ts (frais d\'√©tudes...)','Autres pr√™ts (frais d\'√©tudes...)',2,0),(2731,'Retenues de garantie','Retenues de garantie',2,0),(2733,'Fonds r√©glement√©','Fonds r√©glement√©',2,0),(2738,'Autres','Autres',2,0),(2741,'Titres immobilis√©s de l\'activit√© de portefeuille (T.I.A.P.)','Titres immobilis√©s de l\'activit√© de portefeuille (T.I.A.P.)',2,0),(2742,'Titres participatifs','Titres participatifs',2,0),(2743,'Certificats d\'investissement','Certificats d\'investissement',2,0),(2744,'Parts de fonds commun de placement (F.C.P.)','Parts de fonds commun de placement (F.C.P.)',2,0),(2748,'Autres titres immobilis√©s','Autres titres immobilis√©s',2,0),(2751,'D√©p√¥ts pour loyers d\'avance','D√©p√¥ts pour loyers d\'avance',2,0),(2752,'D√©p√¥ts pour l\'√©lectricit√©','D√©p√¥ts pour l\'√©lectricit√©',2,0),(2753,'D√©p√¥ts pour l\'eau','D√©p√¥ts pour l\'eau',2,0),(2754,'D√©p√¥ts pour le gaz','D√©p√¥ts pour le gaz',2,0),(2755,'D√©p√¥ts pour le t√©l√©phone, le t√©lex, la t√©l√©copie','D√©p√¥ts pour le t√©l√©phone, le t√©lex, la t√©l√©copie',2,0),(2756,'Cautionnements sur march√©s publics','Cautionnements sur march√©s publics',2,0),(2757,'Cautionnements sur autres op√©rations','Cautionnements sur autres op√©rations',2,0),(2758,'Autres d√©p√¥ts et cautionnements','Autres d√©p√¥ts et cautionnements',2,0),(2761,'Pr√™ts et cr√©ances non commerciales','Pr√™ts et cr√©ances non commerciales',2,0),(2762,'Pr√™ts au personnel','Pr√™ts au personnel',2,0),(2763,'Cr√©ances sur l\'Etat','Cr√©ances sur l\'Etat',2,0),(2764,'Titres immobilis√©s','Titres immobilis√©s',2,0),(2765,'D√©p√¥ts et cautionnements vers√©s','D√©p√¥ts et cautionnements vers√©s',2,0),(2767,'Cr√©ances rattach√©es √† des participations','Cr√©ances rattach√©es √† des participations',2,0),(2768,'Immobilisations financi√®res diverses','Immobilisations financi√®res diverses',2,0),(2771,'Cr√©ances rattach√©es √† des participations (groupe)','Cr√©ances rattach√©es √† des participations (groupe)',2,0),(2772,'Cr√©ances rattach√©es √† des participtations (hors groupe)','Cr√©ances rattach√©es √† des participtations (hors groupe)',2,0),(2773,'Cr√©ances rattach√©es √† des soci√©t√©s en participation','Cr√©ances rattach√©es √† des soci√©t√©s en participation',2,0),(2774,'Avances √† des Groupements d\'int√©r√™t √©conomique (G.I.E.)','Avances √† des Groupements d\'int√©r√™t √©conomique (G.I.E.)',2,0),(2781,'Cr√©ances diverses groupe','Cr√©ances diverses groupe',2,0),(2782,'Cr√©ances divers hors groupe','Cr√©ances divers hors groupe',2,0),(2785,'Or et m√©taux pr√©cieux','Or et m√©taux pr√©cieux',2,0),(2811,'Amortissements des frais de recherche et de d√©veloppement','Amortissements des frais de recherche et de d√©veloppement',2,0),(2812,'Amortissements des brevets, licences, concessions et droits similaires','Amortissements des brevets, licences, concessions et droits similaires',2,0),(2813,'Amortissements des logiciels','Amortissements des logiciels',2,0),(2814,'Amortissements des marques','Amortissements des marques',2,0),(2815,'Amortissements du fonds commercial','Amortissements du fonds commercial',2,0),(2816,'Amortissements du droit au bail','Amortissements du droit au bail',2,0),(2817,'Amortissements des investissements de cr√©ation','Amortissements des investissements de cr√©ation',2,0),(2818,'Amortissements des autres droits et valeurs incorporels','Amortissements des autres droits et valeurs incorporels',2,0),(2821,'Amortissements des terrains agricoles et forestiers','Amortissements des terrains agricoles et forestiers',2,0),(2824,'Amortissements des travaux de mise en valeur des terrains','Amortissements des travaux de mise en valeur des terrains',2,0),(2825,'Amortissements des terrains de gisement','Amortissements des terrains de gisement',2,0),(2831,'Amortissements des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol propre','Amortissements des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol propre',2,0),(2832,'Amortissements des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol d\'autrui','Amortissements des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol d\'autrui',2,0),(2833,'Amortissements des ouvrages d\'infrastructure','Amortissements des ouvrages d\'infrastructure',2,0),(2834,'Amortissements des installations techniques','Amortissements des installations techniques',2,0),(2835,'Amortissements des am√©nagements de bureaux','Amortissements des am√©nagements de bureaux',2,0),(2837,'Amortissements des b√¢timents industriels, agricoles et commerciaux mis en concession','Amortissements des b√¢timents industriels, agricoles et commerciaux mis en concession',2,0),(2838,'Amortissements des autres installations et agencements','Amortissements des autres installations et agencements',2,0),(2841,'Amortissements du mat√©riel et outillage industriel et commercial','Amortissements du mat√©riel et outillage industriel et commercial',2,0),(2842,'Amortissements du mat√©riel et outillage agricole','Amortissements du mat√©riel et outillage agricole',2,0),(2843,'Amortissements du mat√©riel d\'emballage r√©cup√©rable et identifiable','Amortissements du mat√©riel d\'emballage r√©cup√©rable et identifiable',2,0),(2844,'Amortissements du mat√©riel et mobilier','Amortissements du mat√©riel et mobilier',2,0),(2845,'Amortissements du mat√©riel de transport','Amortissements du mat√©riel de transport',2,0),(2846,'Amortissements des immobilisations animales et agricoles','Amortissements des immobilisations animales et agricoles',2,0),(2847,'Amortissements des agencements et am√©nagements du mat√©riel','Amortissements des agencements et am√©nagements du mat√©riel',2,0),(2848,'Amortissements des autres mat√©riels','Amortissements des autres mat√©riels',2,0),(2912,'Provisions pour d√©pr√©ciation des brevets, licences, concessions et droits similaires ','Provisions pour d√©pr√©ciation des brevets, licences, concessions et droits similaires ',2,0),(2913,'Provisions pour d√©pr√©ciation des logiciels','Provisions pour d√©pr√©ciation des logiciels',2,0),(2914,'Provisions pour d√©pr√©ciation des marques ','Provisions pour d√©pr√©ciation des marques ',2,0),(2915,'Provisions pour d√©pr√©ciation du fonds commercial','Provisions pour d√©pr√©ciation du fonds commercial',2,0),(2916,'Provisions pour d√©pr√©ciation du droit au bail','Provisions pour d√©pr√©ciation du droit au bail',2,0),(2917,'Provisions pour d√©pr√©ciation des investissements de cr√©ation','Provisions pour d√©pr√©ciation des investissements de cr√©ation',2,0),(2918,'Provisions pour d√©pr√©ciation des autres droits et valeurs incorporels','Provisions pour d√©pr√©ciation des autres droits et valeurs incorporels',2,0),(2919,'Provisions pour d√©pr√©ciation des immobilisations incorporelles en cours','Provisions pour d√©pr√©ciation des immobilisations incorporelles en cours',2,0),(2921,'Provisions pour d√©pr√©ciation des terrains agricoles et forestiers','Provisions pour d√©pr√©ciation des terrains agricoles et forestiers',2,0),(2922,'Provisions pour d√©pr√©ciation des terrains nus','Provisions pour d√©pr√©ciation des terrains nus',2,0),(2923,'Provisions pour d√©pr√©ciation des terrains b√¢tis','Provisions pour d√©pr√©ciation des terrains b√¢tis',2,0),(2924,'Provisions pour d√©pr√©ciation des travaux de mise en valeur des terrains','Provisions pour d√©pr√©ciation des travaux de mise en valeur des terrains',2,0),(2925,'Provisions pour d√©pr√©ciation des terrains de gisement','Provisions pour d√©pr√©ciation des terrains de gisement',2,0),(2926,'Provisions pour d√©pr√©ciation des terrains am√©nag√©s','Provisions pour d√©pr√©ciation des terrains am√©nag√©s',2,0),(2927,'Provisions pour d√©pr√©ciation des terrains mis en concession','Provisions pour d√©pr√©ciation des terrains mis en concession',2,0),(2928,'Provisions pour d√©pr√©ciation des autres terrains','Provisions pour d√©pr√©ciation des autres terrains',2,0),(2929,'Provisions pour d√©pr√©ciation des am√©nagements de terrains en cours','Provisions pour d√©pr√©ciation des am√©nagements de terrains en cours',2,0),(2931,'Provisions pour d√©pr√©ciation des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol propre','Provisions pour d√©pr√©ciation des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol propre',2,0),(2932,'Provisions pour d√©pr√©ciation des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol d\'autrui','Provisions pour d√©pr√©ciation des b√¢timents industriels, agricoles, administratifs et commerciaux sur sol d\'autrui',2,0),(2933,'Provisions pour d√©pr√©ciation des ouvrages d\'infrastructures','Provisions pour d√©pr√©ciation des ouvrages d\'infrastructures',2,0),(2934,'Provisions pour d√©pr√©ciation des installations techniques','Provisions pour d√©pr√©ciation des installations techniques',2,0),(2935,'Provisions pour d√©pr√©ciation des am√©nagements de bureaux','Provisions pour d√©pr√©ciation des am√©nagements de bureaux',2,0),(2937,'Provisions pour d√©pr√©ciation des b√¢timents industriels, agricoles et commerciaux mis en concession','Provisions pour d√©pr√©ciation des b√¢timents industriels, agricoles et commerciaux mis en concession',2,0),(2938,'Provisions pour d√©pr√©ciation des autres installations et agencements','Provisions pour d√©pr√©ciation des autres installations et agencements',2,0),(2939,'Provisions pour d√©pr√©ciation des b√¢timents et installations en cours','Provisions pour d√©pr√©ciation des b√¢timents et installations en cours',2,0),(2941,'Provisions pour d√©pr√©ciation du mat√©riel et outillage industriel et commercial','Provisions pour d√©pr√©ciation du mat√©riel et outillage industriel et commercial',2,0),(2942,'Provisions pour d√©pr√©ciation du mat√©riel et outillage agricole','Provisions pour d√©pr√©ciation du mat√©riel et outillage agricole',2,0),(2943,'Provisions pour d√©pr√©ciation du mat√©riel d\'emballage r√©cup√©rable et identifiable','Provisions pour d√©pr√©ciation du mat√©riel d\'emballage r√©cup√©rable et identifiable',2,0),(2944,'Provisions pour d√©pr√©ciation du mat√©riel et mobilier','Provisions pour d√©pr√©ciation du mat√©riel et mobilier',2,0),(2945,'Provisions pour d√©pr√©ciation du mat√©riel de transport','Provisions pour d√©pr√©ciation du mat√©riel de transport',2,0),(2946,'Provisions pour d√©pr√©ciation des immobilisations animales et agricoles','Provisions pour d√©pr√©ciation des immobilisations animales et agricoles',2,0),(2947,'Provisions pour d√©pr√©ciation des agencements et am√©nagements du mat√©riel','Provisions pour d√©pr√©ciation des agencements et am√©nagements du mat√©riel',2,0),(2948,'Provisions pour d√©pr√©ciation des autres mat√©riels','Provisions pour d√©pr√©ciation des autres mat√©riels',2,0),(2949,'Provisions pour d√©pr√©ciation de mat√©riel en cours','Provisions pour d√©pr√©ciation de mat√©riel en cours',2,0),(2951,'Provisions pour d√©pr√©ciation des avances et acomptes vers√©s sur immobilisations corporelles','Provisions pour d√©pr√©ciation des avances et acomptes vers√©s sur immobilisations corporelles',2,0),(2952,'Provisions pour d√©pr√©ciation des avances et acomptes vers√©s sur immobilisations corporelles','Provisions pour d√©pr√©ciation des avances et acomptes vers√©s sur immobilisations corporelles',2,0),(2961,'Provisions pour d√©pr√©ciation des titres de participation dans les soci√©t√©s sous contr√¥le exclusif','Provisions pour d√©pr√©ciation des titres de participation dans les soci√©t√©s sous contr√¥le exclusif',2,0),(2962,'Provisions pour d√©pr√©ciation des titres de participation dans les soci√©t√©s sous contr√¥le conjoint','Provisions pour d√©pr√©ciation des titres de participation dans les soci√©t√©s sous contr√¥le conjoint',2,0),(2963,'Provisions pour d√©pr√©ciation des titres de participation dans les soci√©t√©s conf√©rant une influence notable','Provisions pour d√©pr√©ciation des titres de participation dans les soci√©t√©s conf√©rant une influence notable',2,0),(2965,'Provisions pour d√©pr√©ciation des participations dans les organismes professionnels','Provisions pour d√©pr√©ciation des participations dans les organismes professionnels',2,0),(2966,'Provisions pour d√©pr√©ciation des parts dans des GIE','Provisions pour d√©pr√©ciation des parts dans des GIE',2,0),(2968,'Provisions pour d√©pr√©ciation des autres titres de participation','Provisions pour d√©pr√©ciation des autres titres de participation',2,0),(2971,'Provisions pour d√©pr√©ciation des pr√™ts et cr√©ances non commerciales','Provisions pour d√©pr√©ciation des pr√™ts et cr√©ances non commerciales',2,0),(2972,'Provisions pour d√©pr√©ciation des pr√™ts au personnel','Provisions pour d√©pr√©ciation des pr√™ts au personnel',2,0),(2973,'Provisions pour d√©pr√©ciation des cr√©ances sur l\'Etat','Provisions pour d√©pr√©ciation des cr√©ances sur l\'Etat',2,0),(2974,'Provisions pour d√©pr√©ciation des titres immobilis√©s','Provisions pour d√©pr√©ciation des titres immobilis√©s',2,0),(2975,'Provisions pour d√©pr√©ciation des d√©p√¥ts et cautionnements vers√©s','Provisions pour d√©pr√©ciation des d√©p√¥ts et cautionnements vers√©s',2,0),(2977,'Provisions pour d√©pr√©ciation des cr√©ances rattach√©es √† des participations et avances √† des GIE ','Provisions pour d√©pr√©ciation des cr√©ances rattach√©es √† des participations et avances √† des GIE ',2,0),(2978,'Provisions pour d√©pr√©ciation des cr√©ances financi√®res diverses','Provisions pour d√©pr√©ciation des cr√©ances financi√®res diverses',2,0),(3111,'Marchandises A1','Marchandises A1',3,0),(3112,'Marchandises A2','Marchandises A2',3,0),(3121,'Marchandises B1','Marchandises B1',3,0),(3122,'Marchandises B2','Marchandises B2',3,0),(3351,'Emballages perdus','Emballages perdus',3,0),(3352,'Emballages r√©cup√©rables non identifiables','Emballages r√©cup√©rables non identifiables',3,0),(3353,'Emballages √† usage mixte','Emballages √† usage mixte',3,0),(3358,'Autres emballages','Autres emballages',3,0),(3411,'Produits en cours P1','Produits en cours P1',3,0),(3412,'Produits en cours P2','Produits en cours P2',3,0),(3421,'Travaux en cours T1','Travaux en cours T1',3,0),(3422,'Travaux en cours T2','Travaux en cours T2',3,0),(3431,'Produits interm√©diaires A','Produits interm√©diaires A',3,0),(3432,'Produits interm√©diaires B','Produits interm√©diaires B',3,0),(3441,'Produits r√©siduels A','Produits r√©siduels A',3,0),(3442,'Produits r√©siduels B','Produits r√©siduels B',3,0),(3511,'Etudes en cours E1','Etudes en cours E1',3,0),(3512,'Etudes en cours E2','Etudes en cours E2',3,0),(3711,'Produits interm√©diaires A','Produits interm√©diaires A',3,0),(3712,'Produits interm√©diaires B','Produits interm√©diaires B',3,0),(3721,'D√©chets ','D√©chets ',3,0),(3722,'Rebuts','Rebuts',3,0),(3723,'Mati√®res et R√©cup√©ration','Mati√®res et R√©cup√©ration',3,0),(3871,'Stock en consignation ','Stock en consignation ',3,0),(3872,'Stock en d√©p√¥t','Stock en d√©p√¥t',3,0),(4011,'Fournisseurs','Fournisseurs',4,0),(4012,'Fournisseurs Groupe','Fournisseurs Groupe',4,0),(4013,'Fournisseurs sou-traitants','Fournisseurs sou-traitants',4,0),(4017,'Fournisseur, retenues de garantie','Fournisseur, retenues de garantie',4,0),(4021,'Fournisseurs, Effets √† payer','Fournisseurs, Effets √† payer',4,0),(4022,'Fournisseurs - Groupe, Effets √† payer','Fournisseurs - Groupe, Effets √† payer',4,0),(4023,'Fournisseurs sous-traitants, Effets √† payer','Fournisseurs sous-traitants, Effets √† payer',4,0),(4081,'Fournisseurs','Fournisseurs',4,0),(4082,'Fournisseurs - Groupe','Fournisseurs - Groupe',4,0),(4083,'Fournisseurs sous-traitants','Fournisseurs sous-traitants',4,0),(4086,'Fournisseurs, int√©r√™ts courus','Fournisseurs, int√©r√™ts courus',4,0),(4091,'Fournisseurs avances et acomptes vers√©s','Fournisseurs avances et acomptes vers√©s',4,0),(4092,'Fournisseurs - Groupe avances et acomptes vers√©s','Fournisseurs - Groupe avances et acomptes vers√©s',4,0),(4093,'Fournisseurs sous-traitants avances et acomptes vers√©s','Fournisseurs sous-traitants avances et acomptes vers√©s',4,0),(4094,'Fournisseurs cr√©ances pour emballages et mat√©riels √† rendre','Fournisseurs cr√©ances pour emballages et mat√©riels √† rendre',4,0),(4098,'Rabais, Remises, Ristournes et autres avoirs √† obtenir','Rabais, Remises, Ristournes et autres avoirs √† obtenir',4,0),(4111,'Clients','Clients',4,1),(4112,'Clients - Groupe','Clients - Groupe',4,0),(4114,'Clients, Etat et Collectivit√©s publiques ','Clients, Etat et Collectivit√©s publiques ',4,0),(4115,'Clients, organismes internationaux','Clients, organismes internationaux',4,0),(4117,'Clients, retenues de garantie','Clients, retenues de garantie',4,0),(4118,'Clients, d√©gr√®vement de Taxes sur la Valeur Ajout√©e (T.V.A.)','Clients, d√©gr√®vement de Taxes sur la Valeur Ajout√©e (T.V.A.)',4,0),(4121,'Clients, Effets √† recevoir','Clients, Effets √† recevoir',4,0),(4122,'Clients - Groupe, Effets √† recevoir','Clients - Groupe, Effets √† recevoir',4,0),(4124,'Etat et Collectivit√©s publiques, Effets √† recevoir','Etat et Collectivit√©s publiques, Effets √† recevoir',4,0),(4125,'Organismes Internationaux, Effets √† recevoir','Organismes Internationaux, Effets √† recevoir',4,0),(4141,'Cr√©ances en compte','Cr√©ances en compte',4,0),(4142,'Effets √† recevoir','Effets √† recevoir',4,0),(4161,'Cr√©ances litigieuses','Cr√©ances litigieuses',4,0),(4162,'Cr√©ances douteuses','Cr√©ances douteuses',4,0),(4181,'Clients, factures √† √©tablir','Clients, factures √† √©tablir',4,0),(4186,'Clients, int√©r√™ts courus','Clients, int√©r√™ts courus',4,0),(4191,'Clients, avances et acomptes re√ßus','Clients, avances et acomptes re√ßus',4,0),(4192,'Clients - Groupe, avances et acomptes re√ßus','Clients - Groupe, avances et acomptes re√ßus',4,0),(4194,'Clients, dettes pour emballages et mat√©riels consign√©s','Clients, dettes pour emballages et mat√©riels consign√©s',4,0),(4198,'Rabais, Remises, Ristournes et autres avoirs √† accorder','Rabais, Remises, Ristournes et autres avoirs √† accorder',4,0),(4211,'Personnel, avances','Personnel, avances',4,0),(4212,'Personnel, acomptes','Personnel, acomptes',4,0),(4213,'Frais avanc√©s et fournitures au personnel','Frais avanc√©s et fournitures au personnel',4,0),(4231,'Personnel, oppositions','Personnel, oppositions',4,0),(4232,'Personnel, saisies-arr√™ts','Personnel, saisies-arr√™ts',4,0),(4233,'Personnel, avis √† tiers d√©tenteur','Personnel, avis √† tiers d√©tenteur',4,0),(4241,'Assistance m√©dicale','Assistance m√©dicale',4,0),(4242,'Allocations familiales','Allocations familiales',4,0),(4245,'Organismes sociaux rattach√©s √† l\'entreprise','Organismes sociaux rattach√©s √† l\'entreprise',4,0),(4248,'Autres oeuvres sociales internes','Autres oeuvres sociales internes',4,0),(4251,'D√©l√©gu√©s du personnel','D√©l√©gu√©s du personnel',4,0),(4252,'Syndicats et Comit√©s d\'entreprises, d\'Etablissement','Syndicats et Comit√©s d\'entreprises, d\'Etablissement',4,0),(4258,'Autres repr√©sentants du personnel','Autres repr√©sentants du personnel',4,0),(4281,'Dettes provisionn√©es pour cong√©s √† payer','Dettes provisionn√©es pour cong√©s √† payer',4,0),(4286,'Autres Charges √† payer','Autres Charges √† payer',4,0),(4287,'Produits √† recevoir','Produits √† recevoir',4,0),(4311,'Prestations familiales','Prestations familiales',4,0),(4312,'Accidents de travail','Accidents de travail',4,0),(4313,'Caisse de retraite obligatoire','Caisse de retraite obligatoire',4,0),(4314,'Caisse de retraite facultative','Caisse de retraite facultative',4,0),(4318,'Autres cotisations sociales','Autres cotisations sociales',4,0),(4331,'Mutuelle','Mutuelle',4,0),(4381,'Charges sociales sur gratifications √† payer','Charges sociales sur gratifications √† payer',4,0),(4382,'Charges sociales sur cong√©s √† payer','Charges sociales sur cong√©s √† payer',4,0),(4386,'Autres charges √† payer','Autres charges √† payer',4,0),(4387,'Produits √† recevoir','Produits √† recevoir',4,0),(4421,'Imp√¥ts et taxes d\'Etat','Imp√¥ts et taxes d\'Etat',4,0),(4422,'Imp√¥ts et taxes pour les collectivit√©s publiques','Taxe touristique',4,1),(4423,'Imp√¥ts et taxes recouvrables sur des obligataires','Imp√¥ts et taxes recouvrables sur des obligataires',4,0),(4424,'Imp√¥ts et taxes recouvrables sur des associ√©s','Imp√¥ts et taxes recouvrables sur des associ√©s',4,0),(4426,'Droits de douane','Droits de douane',4,0),(4428,'Autres imp√¥ts et taxes','Autres imp√¥ts et taxes',4,0),(4431,'T.V.A. factur√©e sur ventes','T.V.A. factur√©e sur ventes',4,0),(4432,'T.V.A. factur√©e sur prestations de services','Taxe collect√©e',4,1),(4433,'T.V.A. factur√©e sur travaux','T.V.A. factur√©e sur travaux',4,0),(4434,'T.V.A. factur√©e sur prodution livr√©e √† soi-m√™me','T.V.A. factur√©e sur prodution livr√©e √† soi-m√™me',4,0),(4435,'T.V.A. sur factures √† √©tablir','T.V.A. sur factures √† √©tablir',4,0),(4441,'Etat, T.V.A. due','Taxe d√©ductible',4,1),(4449,'Etat, cr√©dit de T.V.A. √† reporter','Etat, cr√©dit de T.V.A. √† reporter',4,0),(4451,'T.V.A. r√©cup√©rable sur immobilisations','T.V.A. r√©cup√©rable sur immobilisations',4,0),(4452,'T.V.A. r√©cup√©rable sur achats','T.V.A. r√©cup√©rable sur achats',4,0),(4453,'T.V.A. r√©cup√©rable sur transport','T.V.A. r√©cup√©rable sur transport',4,0),(4454,'T.V.A. r√©cup√©rable sur services ext√©rieurs et autres charges','T.V.A. r√©cup√©rable sur services ext√©rieurs et autres charges',4,0),(4455,'T.V.A. r√©cup√©rable sur factures non parvenues','T.V.A. r√©cup√©rable sur factures non parvenues',4,0),(4456,'T.V.A. transf√©r√©e par d\'autres entreprises','T.V.A. transf√©r√©e par d\'autres entreprises',4,0),(4471,'Imp√¥t G√©n√©ral sur le revenu','Imp√¥t G√©n√©ral sur le revenu',4,0),(4472,'Imp√¥ts sur salaires','Imp√¥ts sur salaires',4,0),(4473,'Contribution nationale','Contribution nationale',4,0),(4474,'Contribution nationale de solidarit√©','Contribution nationale de solidarit√©',4,0),(4478,'Autres imp√¥ts et contributions','Autres imp√¥ts et contributions',4,0),(4486,'Charges √† payer','Charges √† payer',4,0),(4487,'Produits √† recevoir','Produits √† recevoir',4,0),(4491,'Etat, obligations cautionn√©es','Etat, obligations cautionn√©es',4,0),(4492,'Etat, avances et acomptes vers√©s sur imp√¥ts','Etat, avances et acomptes vers√©s sur imp√¥ts',4,0),(4493,'Etat, fonds de dotation √† recevoir','Etat, fonds de dotation √† recevoir',4,0),(4494,'Etat, subventions d\'√©quipement √† recevoir','Etat, subventions d\'√©quipement √† recevoir',4,0),(4495,'Etat, subventions d\'exploitation √† recevoir','Etat, subventions d\'exploitation √† recevoir',4,0),(4496,'Etat, subventions d\'√©quilibre √† recevoir','Etat, subventions d\'√©quilibre √† recevoir',4,0),(4499,'Etat, fonds r√©glement√© provisionn√©','Etat, fonds r√©glement√© provisionn√©',4,0),(4581,'Organismes internationaux, fonds de dotation √† recevoir','Organismes internationaux, fonds de dotation √† recevoir',4,0),(4582,'Organismes internationaux, subventions √† recevoir','Organismes internationaux, subventions √† recevoir',4,0),(4611,'Associ√©s apports en nature','Associ√©s apports en nature',4,0),(4612,'Associ√©s apports en num√©raire','Associ√©s apports en num√©raire',4,0),(4613,'Actionnaires, capital souscrit appel√© non vers√©','Actionnaires, capital souscrit appel√© non vers√©',4,0),(4614,'Associ√©s, capital appel√© non vers√©','Associ√©s, capital appel√© non vers√©',4,0),(4615,'Associ√©s, versements re√ßus sur augmentation de capital','Associ√©s, versements re√ßus sur augmentation de capital',4,0),(4616,'Associ√©s, versements anticip√©s','Associ√©s, versements anticip√©s',4,0),(4617,'Actionnaires d√©faillants','Actionnaires d√©faillants',4,0),(4618,'Associ√©s, autres apports','Associ√©s, autres apports',4,0),(4619,'Associ√©s, capital √† rembourser','Associ√©s, capital √† rembourser',4,0),(4621,'Principal','Principal',4,0),(4626,'Int√©r√™ts courus','Int√©r√™ts courus',4,0),(4711,'D√©biteurs divers','D√©biteurs divers',4,0),(4712,'Cr√©diteurs divers','Cr√©diteurs divers',4,0),(4726,'Titres de participation','Titres de participation',4,0),(4727,'Titres immobilis√©s','Titres immobilis√©s',4,0),(4728,'Titres de placement','Titres de placement',4,0),(4746,'Charges','Charges',4,0),(4747,'Produits','Produits',4,0),(4781,'Diminution des cr√©ances','Diminution des cr√©ances',4,0),(4782,'Augmentation des dettes','Augmentation des dettes',4,0),(4788,'Diff√©rences compens√©es par couverture de charge','Diff√©rences compens√©es par couverture de charge',4,0),(4791,'Augmentation des cr√©ances','Augmentation des cr√©ances',4,0),(4792,'Diminution des dettes','Diminution des dettes',4,0),(4798,'Diff√©rences compens√©es par couverture de change','Diff√©rences compens√©es par couverture de change',4,0),(4811,'Immobilisations incorporelles','Immobilisations incorporelles',4,0),(4812,'Immobilisations corporelles','Immobilisations corporelles',4,0),(4817,'Retenues de garantie','Retenues de garantie',4,0),(4818,'Factures non parvenues','Factures non parvenues',4,0),(4851,'En compte','En compte',4,0),(4852,'Effets √† recevoir','Effets √† recevoir',4,0),(4857,'Retenues de garantie','Retenues de garantie',4,0),(4858,'Factures √† √©tablir','Factures √† √©tablir',4,0),(4911,'Cr√©ances litigieuses','Cr√©ances litigieuses',4,0),(4912,'Cr√©ances douteuses','Cr√©ances douteuses',4,0),(4962,'Associ√©s, comptes courants','Associ√©s, comptes courants',4,0),(4963,'Associ√©s, op√©rations faites en commun','Associ√©s, op√©rations faites en commun',4,0),(4966,'Groupe, comptes courants','Groupe, comptes courants',4,0),(4981,'Cr√©ances sur cessions d\'immobilisations','Cr√©ances sur cessions d\'immobilisations',4,0),(4982,'Cr√©ances sur cessions de titres de placement','Cr√©ances sur cessions de titres de placement',4,0),(4983,'Autres cr√©ances H.A.O.','Autres cr√©ances H.A.O.',4,0),(4991,'Sur op√©rations d\'exploitation','Sur op√©rations d\'exploitation',4,0),(4998,'Sur op√©rations H.A.O.','Sur op√©rations H.A.O.',4,0),(5011,'Titres du Tr√©sor √† court terme','Titres du Tr√©sor √† court terme',5,0),(5012,'Titres d\'organismes financiers','Titres d\'organismes financiers',5,0),(5013,'Bons de caisse √† court terme','Bons de caisse √† court terme',5,0),(5021,'Actions propres ','Actions propres ',5,0),(5022,'Actions cot√©es','Actions cot√©es',5,0),(5023,'Actions non cot√©es','Actions non cot√©es',5,0),(5024,'Actions d√©membr√©es (certificats d\'investissement; droits de vote)','Actions d√©membr√©es (certificats d\'investissement; droits de vote)',5,0),(5025,'Autres titres conf√©rant un droit de propri√©t√©','Autres titres conf√©rant un droit de propri√©t√©',5,0),(5031,'Obligations √©mises par la soci√©t√© et rachet√©es par elle','Obligations √©mises par la soci√©t√© et rachet√©es par elle',5,0),(5032,'Obligations cot√©es','Obligations cot√©es',5,0),(5033,'Obligations non cot√©es','Obligations non cot√©es',5,0),(5035,'Autres titres conf√©rant un droit de cr√©ance','Autres titres conf√©rant un droit de cr√©ance',5,0),(5042,'Bons de souscription d\'actions','Bons de souscription d\'actions',5,0),(5043,'Bons de souscription d\'obligations','Bons de souscription d\'obligations',5,0),(5061,'Titres du Tr√©sor et bons de caisse √† court terme','Titres du Tr√©sor et bons de caisse √† court terme',5,0),(5062,'Actions','Actions',5,0),(5063,'Obligations','Obligations',5,0),(5181,'Warents','Warents',5,0),(5182,'Billets de fonds','Billets de fonds',5,0),(5185,'Ch√®ques de voyage','Ch√®ques de voyage',5,0),(5186,'Coupons √©chus','Coupons √©chus',5,0),(5187,'Int√©r√™ts √©chus des obligations','Int√©r√™ts √©chus des obligations',5,0),(5211,'Banque X','Banque X',5,0),(5212,'Banque Y','Banque Y',5,0),(5711,'en unit√©s mon√©taires l√©gales','en unit√©s mon√©taires l√©gales',5,0),(5712,'en devises','en devises',5,0),(5721,'en unit√©s mon√©taires l√©gales','en unit√©s mon√©taires l√©gales',5,0),(5722,'en devises','en devises',5,0),(5731,'en unit√©s mon√©taires l√©gales','en unit√©s mon√©taires l√©gales',5,0),(5732,'en devises','en devises',5,0),(6011,'dans la R√©gion','dans la R√©gion',6,0),(6012,'hors R√©gion','hors R√©gion',6,0),(6013,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',6,0),(6014,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',6,0),(6019,'Rabais, Remises et Ristournes obtenues (non ventil√©s)','Rabais, Remises et Ristournes obtenues (non ventil√©s)',6,0),(6021,'dans la R√©gion','dans la R√©gion',6,0),(6022,'hors R√©gion','hors R√©gion',6,0),(6023,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',6,0),(6024,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',6,0),(6029,'Rabais, Remises et Ristournes obtenus (non ventil√©s)','Rabais, Remises et Ristournes obtenus (non ventil√©s)',6,0),(6031,'Variations des stocks de marchandises','Variations des stocks de marchandises',6,0),(6032,'Variations des stocks de mati√®res premi√®res et fournitures li√©es','Variations des stocks de mati√®res premi√®res et fournitures li√©es',6,0),(6033,'Variations des stocks d\'autres approvisionnements','Variations des stocks d\'autres approvisionnements',6,0),(6041,'Mati√®res consommables','Mati√®res consommables',6,0),(6042,'Mati√®res combustibles ','Mati√®res combustibles ',6,0),(6043,'Produits d\'entretien','Produits d\'entretien',6,0),(6044,'Fournitures d\'atelier et d\'usine','Fournitures d\'atelier et d\'usine',6,0),(6046,'Fournitures de magasin','Fournitures de magasin',6,0),(6047,'Fournitures de bureau','Fournitures de bureau',6,0),(6049,'Rabais, Remises et Ristournes obtenus (non ventil√©s)','Rabais, Remises et Ristournes obtenus (non ventil√©s)',6,0),(6051,'Fournitures non stockables - Eau','Fournitures non stockables - Eau',6,0),(6052,'Fournitures non stockables - Electricit√©','Fournitures non stockables - Electricit√©',6,0),(6053,'Fournitures non stockables - Autres √©nergies','Fournitures non stockables - Autres √©nergies',6,0),(6054,'Fournitures d\'entretien non stockables','Fournitures d\'entretien non stockables',6,0),(6055,'Fournitures de bureau non stockables','Fournitures de bureau non stockables',6,0),(6056,'Achats de petit mat√©riel et outillage','Achats de petit mat√©riel et outillage',6,0),(6057,'Achats d\'√©tudes et prestations de services','Achats d\'√©tudes et prestations de services',6,0),(6058,'Achats de travaux, mat√©riels et √©quipements','Achats de travaux, mat√©riels et √©quipements',6,0),(6059,'Rabais, Remises et Ristournes obtenus (non ventil√©s)','Rabais, Remises et Ristournes obtenus (non ventil√©s)',6,0),(6081,'Emballages perdus','Emballages perdus',6,0),(6082,'Emballages r√©cup√©rables non identifiables','Emballages r√©cup√©rables non identifiables',6,0),(6083,'Emballages √† usage mixte','Emballages √† usage mixte',6,0),(6089,'Rabais, Remises et Ristournes obtenues (non ventil√©s)','Rabais, Remises et Ristournes obtenues (non ventil√©s)',6,0),(6181,'Voyages et d√©placements ','Voyages et d√©placements ',6,0),(6182,'Transports entre √©tablissements ou chantiers ','Transports entre √©tablissements ou chantiers ',6,0),(6183,'Transports administratifs','Transports administratifs',6,0),(6221,'Locations de terrains','Locations de terrains',6,0),(6222,'Locations de b√¢timents','Locations de b√¢timents',6,0),(6223,'Locations de mat√©riels et outillages ','Locations de mat√©riels et outillages ',6,0),(6224,'Malis sur emballages','Malis sur emballages',6,0),(6225,'Locations d\'emballages','Locations d\'emballages',6,0),(6228,'Locations et charges locatives diverses','Locations et charges locatives diverses',6,0),(6232,'Cr√©dit-bail immobilier','Cr√©dit-bail immobilier',6,0),(6233,'Cr√©dit-bail mobilier','Cr√©dit-bail mobilier',6,0),(6235,'Contrats assimil√©s','Contrats assimil√©s',6,0),(6241,'Entretien et r√©parations des biens immobiliers','Entretien et r√©parations des biens immobiliers',6,0),(6242,'Entretien et r√©parations des biens mobiliers','Entretien et r√©parations des biens mobiliers',6,0),(6243,'Maintenance','Maintenance',6,0),(6248,'Autres entretiens et r√©parations','Autres entretiens et r√©parations',6,0),(6251,'Assurances multirisques','Assurances multirisques',6,0),(6252,'Assurances mat√©riel de transport','Assurances mat√©riel de transport',6,0),(6253,'Assurances risques d\'exploitation','Assurances risques d\'exploitation',6,0),(6254,'Assurances responsabilit√© du producteur','Assurances responsabilit√© du producteur',6,0),(6255,'Assurances insolvabilit√© clients ','Assurances insolvabilit√© clients ',6,0),(6256,'Assurances transporst sur achats','Assurances transporst sur achats',6,0),(6257,'Assurances transport sur ventes','Assurances transport sur ventes',6,0),(6258,'Autres primes d\'assurances','Autres primes d\'assurances',6,0),(6261,'Etudes et recherches','Etudes et recherches',6,0),(6265,'Documentation g√©n√©rale','Documentation g√©n√©rale',6,0),(6266,'Documentation technique','Documentation technique',6,0),(6271,'Annonces, insertions','Annonces, insertions',6,0),(6272,'Catalogues, imprim√©s publicitaires','Catalogues, imprim√©s publicitaires',6,0),(6273,'Echantillons','Echantillons',6,0),(6274,'Foires et expositions ','Foires et expositions ',6,0),(6275,'Publications','Publications',6,0),(6276,'Cadeaux √† la client√®le','Cadeaux √† la client√®le',6,0),(6277,'Frais de colloques, s√©minaires, conf√©rences','Frais de colloques, s√©minaires, conf√©rences',6,0),(6278,'Autres charges de publicit√© et relations publiques','Autres charges de publicit√© et relations publiques',6,0),(6281,'Frais de t√©l√©phone','Frais de t√©l√©phone',6,0),(6282,'Frais de t√©lex','Frais de t√©lex',6,0),(6283,'Frais de t√©l√©copie','Frais de t√©l√©copie',6,0),(6288,'Autres frais de t√©l√©communications','Autres frais de t√©l√©communications',6,0),(6311,'Frais sur titres (achat, vente, garde)','Frais sur titres (achat, vente, garde)',6,0),(6312,'Frais sur effets','Frais sur effets',6,0),(6313,'Location de coffres','Location de coffres',6,0),(6315,'Commissions sur cartes de cr√©dit','Commissions sur cartes de cr√©dit',6,0),(6316,'Frais d\'√©mission d\'emprunts','Frais d\'√©mission d\'emprunts',6,0),(6318,'Autres frais bancaires','Autres frais bancaires',6,0),(6321,'Commissions et courtages sur achats ','Commissions et courtages sur achats ',6,0),(6322,'Commissions et courtages sur ventes','Commissions et courtages sur ventes',6,0),(6323,'R√©mun√©rations des transitaires','R√©mun√©rations des transitaires',6,0),(6324,'Honoraires ','Honoraires ',6,0),(6325,'Frais d\'actes et de contentieux','Frais d\'actes et de contentieux',6,0),(6328,'Divers frais','Divers frais',6,0),(6342,'Redevances pour brevets, licences, concessions et droits similaires','Redevances pour brevets, licences, concessions et droits similaires',6,0),(6343,'Redevances pour logiciels','Redevances pour logiciels',6,0),(6344,'Redevances pour marques','Redevances pour marques',6,0),(6351,'Cotisations','Cotisations',6,0),(6358,'Concours divers','Concours divers',6,0),(6371,'Personnel int√©rimaire','Personnel int√©rimaire',6,0),(6372,'Personnel d√©tach√© ou pr√™t√© √† l\'entreprise','Personnel d√©tach√© ou pr√™t√© √† l\'entreprise',6,0),(6381,'Frais de recrutement du personnel','Frais de recrutement du personnel',6,0),(6382,'Frais de d√©m√©nagement','Frais de d√©m√©nagement',6,0),(6383,'R√©ceptions ','R√©ceptions ',6,0),(6384,'Missions','Missions',6,0),(6411,'Imp√¥ts fonciers et taxes annexes','Imp√¥ts fonciers et taxes annexes',6,0),(6412,'Patentes, licences et taxes annexes','Patentes, licences et taxes annexes',6,0),(6413,'Taxes sur appointements et salaires','Taxes sur appointements et salaires',6,0),(6414,'Taxes d\'apprentissage','Taxes d\'apprentissage',6,0),(6415,'Formation professionnelle continue','Formation professionnelle continue',6,0),(6418,'Autres imp√¥ts et taxes directs','Autres imp√¥ts et taxes directs',6,0),(6461,'Droits de mutation','Droits de mutation',6,0),(6462,'Droits de timbre','Droits de timbre',6,0),(6463,'Taxes sur les v√©hicules de soci√©t√©','Taxes sur les v√©hicules de soci√©t√©',6,0),(6464,'Vignettes','Vignettes',6,0),(6468,'Autres droits','Autres droits',6,0),(6471,'P√©nalit√©s d\'assiette, imp√¥ts directs','P√©nalit√©s d\'assiette, imp√¥ts directs',6,0),(6472,'P√©nalit√©s d\'assiette, imp√¥ts indirects','P√©nalit√©s d\'assiette, imp√¥ts indirects',6,0),(6473,'P√©nalit√©s de recouvrement, imp√¥ts directs','P√©nalit√©s de recouvrement, imp√¥ts directs',6,0),(6474,'P√©nalit√©s de recouvrement, imp√¥ts indirects','P√©nalit√©s de recouvrement, imp√¥ts indirects',6,0),(6478,'Autres amendes p√©nales et fiscales','Autres amendes p√©nales et fiscales',6,0),(6511,'Clients','Clients',6,0),(6515,'Autres d√©biteurs','Autres d√©biteurs',6,0),(6521,'Quote-part transf√©r√©e de b√©n√©fices (comptabilit√© du g√©rant)','Quote-part transf√©r√©e de b√©n√©fices (comptabilit√© du g√©rant)',6,0),(6525,'Pertes imput√©es par transfert (comptabilit√© des associ√©s non g√©rants)','Pertes imput√©es par transfert (comptabilit√© des associ√©s non g√©rants)',6,0),(6581,'Jetons de pr√©sence et autres r√©mun√©rations d\'administrateurs','Jetons de pr√©sence et autres r√©mun√©rations d\'administrateurs',6,0),(6582,'Dons','Dons',6,0),(6583,'M√©c√©nat','M√©c√©nat',6,0),(6591,'sur risques √† court terme','sur risques √† court terme',6,0),(6593,'sur stocks','sur stocks',6,0),(6594,'sur cr√©ances','sur cr√©ances',6,0),(6598,'Autres charges provisionn√©es','Autres charges provisionn√©es',6,0),(6611,'Appointements salaires et commissions','Appointements salaires et commissions',6,0),(6612,'Primes et gratifications','Primes et gratifications',6,0),(6613,'Cong√©s pay√©s','Cong√©s pay√©s',6,0),(6614,'Indemnit√©s de pr√©avis, de licenciement et de recherche d\'embauche','Indemnit√©s de pr√©avis, de licenciement et de recherche d\'embauche',6,0),(6615,'Indemnit√©s de maladie vers√©es aux travailleurs','Indemnit√©s de maladie vers√©es aux travailleurs',6,0),(6616,'Suppl√©ment familial','Suppl√©ment familial',6,0),(6617,'Avantages en nature','Avantages en nature',6,0),(6618,'Autres r√©mun√©rations directes','Autres r√©mun√©rations directes',6,0),(6621,'Appointements salaires et commissions','Appointements salaires et commissions',6,0),(6622,'Primes et gratifications ','Primes et gratifications ',6,0),(6623,'Cong√©s pay√©s','Cong√©s pay√©s',6,0),(6624,'Indemnit√©s de pr√©avis, de licenciement et de recherche d\'embauche','Indemnit√©s de pr√©avis, de licenciement et de recherche d\'embauche',6,0),(6625,'Indemnit√©s de maladie vers√©es aux travailleurs','Indemnit√©s de maladie vers√©es aux travailleurs',6,0),(6626,'Suppl√©ment familial','Suppl√©ment familial',6,0),(6627,'Avantages en nature','Avantages en nature',6,0),(6628,'Autres r√©mun√©rations directes','Autres r√©mun√©rations directes',6,0),(6631,'Indemnit√©s de logement','Indemnit√©s de logement',6,0),(6632,'Indemnit√©s de repr√©sentation','Indemnit√©s de repr√©sentation',6,0),(6633,'Indemnit√©s d\'exploitation','Indemnit√©s d\'exploitation',6,0),(6638,'Autres indemnit√©s et avantages divers','Autres indemnit√©s et avantages divers',6,0),(6641,'Charges sociales sur r√©mun√©ration du personnel national','Charges sociales sur r√©mun√©ration du personnel national',6,0),(6642,'Charges sociales sur r√©mun√©ration du personnel non national','Charges sociales sur r√©mun√©ration du personnel non national',6,0),(6661,'R√©mun√©ration du travail de l\'exploitant','R√©mun√©ration du travail de l\'exploitant',6,0),(6662,'Charges sociales','Charges sociales',6,0),(6671,'Personnel int√©rimaire','Personnel int√©rimaire',6,0),(6672,'Personnel d√©tach√© ou pr√™t√© √† l\'entreprise','Personnel d√©tach√© ou pr√™t√© √† l\'entreprise',6,0),(6681,'Versements aux Syndicats et Comit√©s d\'entreprise, d\'√©tablissement','Versements aux Syndicats et Comit√©s d\'entreprise, d\'√©tablissement',6,0),(6682,'Versements aux Comit√©s d\'hygi√®ne et de s√©curit√©','Versements aux Comit√©s d\'hygi√®ne et de s√©curit√©',6,0),(6683,'Versements aux autres oeuvres sociales','Versements aux autres oeuvres sociales',6,0),(6684,'M√©decine du travail et pharmacie','M√©decine du travail et pharmacie',6,0),(6711,'Emprunts obligataires','Emprunts obligataires',6,0),(6712,'Emprunts aupr√®s des √©tablissements de cr√©dit','Emprunts aupr√®s des √©tablissements de cr√©dit',6,0),(6713,'Dettes li√©es √† des participations','Dettes li√©es √† des participations',6,0),(6721,'Int√©r√™ts dans loyers de cr√©dit-bail immobilier','Int√©r√™ts dans loyers de cr√©dit-bail immobilier',6,0),(6722,'Int√©r√™ts dans loyers de cr√©dit-bail mobilier','Int√©r√™ts dans loyers de cr√©dit-bail mobilier',6,0),(6723,'Int√©r√™ts dans loyers des autres contrats','Int√©r√™ts dans loyers des autres contrats',6,0),(6741,'Avances re√ßues et d√©p√¥ts cr√©diteurs ','Avances re√ßues et d√©p√¥ts cr√©diteurs ',6,0),(6742,'Comptes courants bloqu√©s','Comptes courants bloqu√©s',6,0),(6743,'Int√©r√™ts sur obligations cautionn√©es','Int√©r√™ts sur obligations cautionn√©es',6,0),(6744,'Int√©r√™ts sur dettes commerciales','Int√©r√™ts sur dettes commerciales',6,0),(6745,'Int√©r√™ts bancaires et sur op√©rations de tr√©sorerie et d\'escompte','Int√©r√™ts bancaires et sur op√©rations de tr√©sorerie et d\'escompte',6,0),(6748,'Int√©r√™ts sur dettes diverses','Int√©r√™ts sur dettes diverses',6,0),(6781,'sur rentes viag√®res','sur rentes viag√®res',6,0),(6782,'sur op√©rations financi√®res ','sur op√©rations financi√®res ',6,0),(6784,'sur instruments de tr√©sorerie','sur instruments de tr√©sorerie',6,0),(6791,'sur risques financiers','sur risques financiers',6,0),(6795,'sur titres de placement','sur titres de placement',6,0),(6798,'Autres charges provisionn√©es financi√®res','Autres charges provisionn√©es financi√®res',6,0),(6811,'Dotations aux amortissements des charges immobilis√©es','Dotations aux amortissements des charges immobilis√©es',6,0),(6812,'Dotations aux amortissements des immobilisations incorporelles','Dotations aux amortissements des immobilisations incorporelles',6,0),(6813,'Dotations aux amortissements des immobilisations corporelles','Dotations aux amortissements des immobilisations corporelles',6,0),(6872,'Dotations aux amortissements des primes de remboursements des obligations','Dotations aux amortissements des primes de remboursements des obligations',6,0),(6878,'Autres dotations aux amortissements √† caract√®re financier','Autres dotations aux amortissements √† caract√®re financier',6,0),(6911,'pour risques et charges','pour risques et charges',6,0),(6912,'pour grosses r√©parations ','pour grosses r√©parations ',6,0),(6913,'pour d√©pr√©ciation des immobilisations incorporelles','pour d√©pr√©ciation des immobilisations incorporelles',6,0),(6914,'pour d√©pr√©ciation des immobilisations corporelles','pour d√©pr√©ciation des immobilisations corporelles',6,0),(6971,'pour risques et charges','pour risques et charges',6,0),(6972,'pour d√©pr√©ciation des immobilisations financi√®res','pour d√©pr√©ciation des immobilisations financi√®res',6,0),(7011,'dans la R√©gion','dans la R√©gion',7,0),(7012,'hors R√©gion','hors R√©gion',7,0),(7013,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',7,0),(7014,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',7,0),(7021,'dans la R√©gion','dans la R√©gion',7,0),(7022,'hors R√©gion','hors R√©gion',7,0),(7023,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',7,0),(7024,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',7,0),(7031,'dans la R√©gion','dans la R√©gion',7,0),(7032,'hors R√©gion','hors R√©gion',7,0),(7033,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',7,0),(7034,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',7,0),(7041,'dans la R√©gion','dans la R√©gion',7,0),(7042,'hors R√©gion','hors R√©gion',7,0),(7043,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',7,0),(7044,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',7,0),(7051,'dans la R√©gion','dans la R√©gion',7,0),(7052,'hors R√©gion','hors R√©gion',7,0),(7053,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',7,0),(7054,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',7,0),(7061,'dans la R√©gion','dans la R√©gion',7,0),(7062,'hors R√©gion','hors R√©gion',7,0),(7063,'aux entreprises du groupe dans la R√©gion','aux entreprises du groupe dans la R√©gion',7,0),(7064,'aux entreprises du groupe hors R√©gion','aux entreprises du groupe hors R√©gion',7,0),(7071,'Ports, emballages perdus et autres frais factur√©s','Ports, emballages perdus et autres frais factur√©s',7,0),(7072,'Commissions et courtages','Commissions et courtages',7,0),(7073,'Locations','Location de chambre',7,1),(7074,'Bonis sur reprises et cessions d\'emballages','Bonis sur reprises et cessions d\'emballages',7,0),(7075,'Mise √† disposition de personnel','Mise √† disposition de personnel',7,0),(7076,'Redevances pour brevets, logiciels, marques et droits similaires','Redevances pour brevets, logiciels, marques et droits similaires',7,0),(7077,'Services exploit√©s dans l\'int√©r√™t du personnel','Services exploit√©s dans l\'int√©r√™t du personnel',7,0),(7078,'Autres produits accessoires','Autres produits accessoires',7,0),(7181,'Vers√©es par l\'Etat et les collectivit√©s publiques','Vers√©es par l\'Etat et les collectivit√©s publiques',7,0),(7182,'Vers√©es par les organismes internationaux','Vers√©es par les organismes internationaux',7,0),(7183,'Vers√©es par des tiers','Vers√©es par des tiers',7,0),(7341,'Produits en cours','Produits en cours',7,0),(7342,'Travaux en cours ','Travaux en cours ',7,0),(7351,'Etudes en cours','Etudes en cours',7,0),(7352,'Prestations de services en cours','Prestations de services en cours',7,0),(7371,'Produits interm√©diaires','Produits interm√©diaires',7,0),(7372,'Produits r√©siduels','Produits r√©siduels',7,0),(7521,'Quote-part transf√©r√©e de pertes (comptabilit√© du g√©rant)','Quote-part transf√©r√©e de pertes (comptabilit√© du g√©rant)',7,0),(7525,'B√©n√©fices attribu√©s par transfert (comptabilit√© des associ√©s non g√©rants)','B√©n√©fices attribu√©s par transfert (comptabilit√© des associ√©s non g√©rants)',7,0),(7581,'Jetons de pr√©sence et autres r√©mun√©rations d\'administrateurs','Jetons de pr√©sence et autres r√©mun√©rations d\'administrateurs',7,0),(7582,'Indemnit√©s d\'assurances re√ßues','Indemnit√©s d\'assurances re√ßues',7,0),(7591,'sur risques √† court terme','sur risques √† court terme',7,0),(7593,'sur stocks','sur stocks',7,0),(7594,'sur cr√©ances','sur cr√©ances',7,0),(7598,'sur autres charges provisionn√©es','sur autres charges provisionn√©es',7,0),(7781,'sur rentes viag√®res ','sur rentes viag√®res ',7,0),(7782,'sur op√©rations financi√®res ','sur op√©rations financi√®res ',7,0),(7784,'sur instruments de tr√©sorerie','sur instruments de tr√©sorerie',7,0),(7791,'sur risques financiers ','sur risques financiers ',7,0),(7795,'sur titres de placement','sur titres de placement',7,0),(7798,'autres charges provisionn√©es financi√®res ','autres charges provisionn√©es financi√®res ',7,0),(7911,'pour risques et charges','pour risques et charges',7,0),(7912,'pour grosses r√©parations','pour grosses r√©parations',7,0),(7913,'pour d√©pr√©ciation des immobilisations incorporelles','pour d√©pr√©ciation des immobilisations incorporelles',7,0),(7914,'pour d√©pr√©ciation des immobilisations corporelles','pour d√©pr√©ciation des immobilisations corporelles',7,0),(7971,'pour risques et charges','pour risques et charges',7,0),(7972,'pour d√©pr√©ciation des immobilisations financi√®res','pour d√©pr√©ciation des immobilisations financi√®res',7,0),(8911,'Activit√©s exerc√©es dans l\'Etat','Activit√©s exerc√©es dans l\'Etat',8,0),(8912,'Activit√©s exerc√©es dans les autres Etats de la R√©gion','Activit√©s exerc√©es dans les autres Etats de la R√©gion',8,0),(8913,'Activit√©s exerc√©es hors R√©gion','Activit√©s exerc√©es hors R√©gion',8,0),(8991,'D√©gr√®vements ','D√©gr√®vements ',8,0),(8994,'Annulations pour pertes r√©troactives','Annulations pour pertes r√©troactives',8,0),(9011,'Cr√©dits confirm√©s obtenus ','Cr√©dits confirm√©s obtenus ',9,0),(9012,'Emprunts restant √† encaisser','Emprunts restant √† encaisser',9,0),(9013,'Facilit√©s de financement renouvelables','Facilit√©s de financement renouvelables',9,0),(9014,'Facilit√©s d\'√©mission','Facilit√©s d\'√©mission',9,0),(9018,'Autres engagements de financement obtenus','Autres engagements de financement obtenus',9,0),(9021,'Avals obtenus','Avals obtenus',9,0),(9022,'Cautions, garanties obtenues','Cautions, garanties obtenues',9,0),(9023,'Hypoth√®ques obtenues','Hypoth√®ques obtenues',9,0),(9024,'Effets endoss√©s par des tiers','Effets endoss√©s par des tiers',9,0),(9028,'Autres garanties obtenues','Autres garanties obtenues',9,0),(9031,'Achats de marchandises √† terme','Achats de marchandises √† terme',9,0),(9032,'Achats √† terme de devises','Achats √† terme de devises',9,0),(9033,'Commandes fermes des clients','Commandes fermes des clients',9,0),(9038,'Autres engagements r√©ciproques','Autres engagements r√©ciproques',9,0),(9041,'Abandons de cr√©ances conditionnels','Abandons de cr√©ances conditionnels',9,0),(9043,'Ventes avec clause de r√©serve de propri√©t√©','Ventes avec clause de r√©serve de propri√©t√©',9,0),(9048,'Divers engagements obtenus','Divers engagements obtenus',9,0),(9051,'Cr√©dits accord√©s non d√©caiss√©s','Cr√©dits accord√©s non d√©caiss√©s',9,0),(9058,'Autres engagements de financement accord√©s','Autres engagements de financement accord√©s',9,0),(9061,'Avals accord√©s','Avals accord√©s',9,0),(9062,'Cautions, garanties accord√©es','Cautions, garanties accord√©es',9,0),(9063,'Hypoth√®ques accord√©es','Hypoth√®ques accord√©es',9,0),(9064,'Effets endoss√©s par l\'entreprise','Effets endoss√©s par l\'entreprise',9,0),(9068,'Autres garanties accord√©es','Autres garanties accord√©es',9,0),(9071,'Ventes de marchandises √† terme','Ventes de marchandises √† terme',9,0),(9072,'Ventes √† terme de devises ','Ventes √† terme de devises ',9,0),(9073,'Commandes fermes aux fournisseurs ','Commandes fermes aux fournisseurs ',9,0),(9078,'Autres engagements r√©ciproques','Autres engagements r√©ciproques',9,0),(9081,'Annnulations conditionnelles de dettes','Annnulations conditionnelles de dettes',9,0),(9082,'Engagements de retraite','Engagements de retraite',9,0),(9083,'Achats avec clause de r√©serve de propri√©t√©','Achats avec clause de r√©serve de propri√©t√©',9,0),(9088,'Divers engagements accord√©s','Divers engagements accord√©s',9,0);
/*!40000 ALTER TABLE `plan_comptable_syscohada` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `prix_chambre_ttc`
--

DROP TABLE IF EXISTS `prix_chambre_ttc`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `prix_chambre_ttc` (
  `idPrixTTC` int(11) NOT NULL AUTO_INCREMENT,
  `idProfile` int(11) NOT NULL,
  `idTypeChambre` int(11) NOT NULL,
  `PrixTTC` int(11) NOT NULL,
  PRIMARY KEY (`idPrixTTC`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `prix_chambre_ttc`
--

LOCK TABLES `prix_chambre_ttc` WRITE;
/*!40000 ALTER TABLE `prix_chambre_ttc` DISABLE KEYS */;
/*!40000 ALTER TABLE `prix_chambre_ttc` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `profiles_client`
--

DROP TABLE IF EXISTS `profiles_client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `profiles_client` (
  `IdProfile` int(11) NOT NULL AUTO_INCREMENT,
  `Profile` varchar(225) NOT NULL,
  `Disponible` tinyint(1) NOT NULL DEFAULT '1',
  `idTypeClient` int(11) NOT NULL,
  PRIMARY KEY (`IdProfile`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `profiles_client`
--

LOCK TABLES `profiles_client` WRITE;
/*!40000 ALTER TABLE `profiles_client` DISABLE KEYS */;
/*!40000 ALTER TABLE `profiles_client` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `recevoir_occup`
--

DROP TABLE IF EXISTS `recevoir_occup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `recevoir_occup` (
  `NumRecevoir` int(11) NOT NULL AUTO_INCREMENT,
  `NumOccupation` int(11) NOT NULL,
  `MatriculeRecepteur` varchar(10) NOT NULL,
  `CodeClient` int(11) NOT NULL,
  `Date` datetime NOT NULL,
  PRIMARY KEY (`NumRecevoir`),
  KEY `CodeClient` (`CodeClient`),
  KEY `MatriculeRecepteur` (`MatriculeRecepteur`),
  KEY `NumOccupation` (`NumOccupation`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `recevoir_occup`
--

LOCK TABLES `recevoir_occup` WRITE;
/*!40000 ALTER TABLE `recevoir_occup` DISABLE KEYS */;
/*!40000 ALTER TABLE `recevoir_occup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `recu_initial`
--

DROP TABLE IF EXISTS `recu_initial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `recu_initial` (
  `IdRecuInitial` int(11) NOT NULL,
  `IdService` int(11) NOT NULL,
  `Type` varchar(50) NOT NULL,
  `Initial` varchar(15) NOT NULL,
  `Numero` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdRecuInitial`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `recu_initial`
--

LOCK TABLES `recu_initial` WRITE;
/*!40000 ALTER TABLE `recu_initial` DISABLE KEYS */;
INSERT INTO `recu_initial` VALUES (1,3,'R√©√ßu de payement de location','RREC',0),(2,4,'R√©√ßu de payement de restauration','RRES',0),(3,3,'R√©√ßu d\'avance sur location','RRECA',0),(4,3,'R√©√ßu de d√©p√¥t sur compte client','RCPTD',0),(5,3,'Re√ßu de restitution de montant de location','RRML',0),(6,3,'Re√ßu de restitution d\'avance sur location','RRAL',0),(7,4,'Re√ßu de retrait sur compte client','RRCC',0),(8,4,'Re√ßu de restitution de montant de restauration','RRMR',0),(9,4,'Re√ßu de payement de bar','RBAR',0),(10,4,'Recu de restitution de montant de bar','RRMB',0);
/*!40000 ALTER TABLE `recu_initial` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `repas_complet_resto`
--

DROP TABLE IF EXISTS `repas_complet_resto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `repas_complet_resto` (
  `IdRepasCResto` int(11) NOT NULL AUTO_INCREMENT,
  `CodeClient` int(11) NOT NULL DEFAULT '0',
  `DateArrivee` datetime NOT NULL,
  `DateDepart` datetime DEFAULT NULL,
  `DureeEnMinutes` int(11) NOT NULL DEFAULT '0',
  `TotalAPayer` int(11) NOT NULL DEFAULT '0',
  `MontantTotalEncaisse` int(11) NOT NULL DEFAULT '0',
  `IdTableResto` int(11) NOT NULL,
  `MatriculeCaissier` varchar(50) NOT NULL,
  `Facture` varchar(50) DEFAULT '',
  `FactureMiseAjour` tinyint(1) NOT NULL DEFAULT '0',
  `NumOccupation` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdRepasCResto`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `repas_complet_resto`
--

LOCK TABLES `repas_complet_resto` WRITE;
/*!40000 ALTER TABLE `repas_complet_resto` DISABLE KEYS */;
/*!40000 ALTER TABLE `repas_complet_resto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reservation`
--

DROP TABLE IF EXISTS `reservation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reservation` (
  `NumReservation` int(11) NOT NULL AUTO_INCREMENT,
  `DateDemande` datetime NOT NULL,
  `DateOccupation` datetime NOT NULL,
  `DureeOccupation` int(11) NOT NULL,
  `Cout` int(11) NOT NULL DEFAULT '0',
  `Avance` int(11) NOT NULL DEFAULT '0',
  `CodeClient` int(11) NOT NULL,
  `IdGroupe` int(11) NOT NULL DEFAULT '0',
  `IdProfile` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`NumReservation`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reservation`
--

LOCK TABLES `reservation` WRITE;
/*!40000 ALTER TABLE `reservation` DISABLE KEYS */;
/*!40000 ALTER TABLE `reservation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `service_entreprise`
--

DROP TABLE IF EXISTS `service_entreprise`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `service_entreprise` (
  `Id_se` int(11) NOT NULL,
  `Nom` varchar(160) NOT NULL,
  PRIMARY KEY (`Id_se`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `service_entreprise`
--

LOCK TABLES `service_entreprise` WRITE;
/*!40000 ALTER TABLE `service_entreprise` DISABLE KEYS */;
INSERT INTO `service_entreprise` VALUES (1,'Administration'),(2,'Comptabilit√©'),(3,'R√©ception'),(4,'Restaurant - Bar');
/*!40000 ALTER TABLE `service_entreprise` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `table_resto`
--

DROP TABLE IF EXISTS `table_resto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `table_resto` (
  `IdTableResto` int(11) NOT NULL AUTO_INCREMENT,
  `Nom` varchar(50) NOT NULL,
  `Occupee` tinyint(1) NOT NULL DEFAULT '0',
  `Supprime` tinyint(1) NOT NULL DEFAULT '0',
  `Bar` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`IdTableResto`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `table_resto`
--

LOCK TABLES `table_resto` WRITE;
/*!40000 ALTER TABLE `table_resto` DISABLE KEYS */;
INSERT INTO `table_resto` VALUES (1,'Table 1',0,0,0),(2,'Table 2',0,0,0),(3,'Table 1',0,0,1),(4,'Table 2',0,0,1);
/*!40000 ALTER TABLE `table_resto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taux`
--

DROP TABLE IF EXISTS `taux`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taux` (
  `idTaux` int(11) NOT NULL,
  `Nom` varchar(30) NOT NULL,
  `Valeur` float NOT NULL,
  PRIMARY KEY (`idTaux`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taux`
--

LOCK TABLES `taux` WRITE;
/*!40000 ALTER TABLE `taux` DISABLE KEYS */;
INSERT INTO `taux` VALUES (1,'TVA',0.18),(2,'Taxe touristique',0.04);
/*!40000 ALTER TABLE `taux` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `type_categorie_menu`
--

DROP TABLE IF EXISTS `type_categorie_menu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `type_categorie_menu` (
  `IdTypeCatMenu` int(11) NOT NULL,
  `Libelle` varchar(50) NOT NULL,
  PRIMARY KEY (`IdTypeCatMenu`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `type_categorie_menu`
--

LOCK TABLES `type_categorie_menu` WRITE;
/*!40000 ALTER TABLE `type_categorie_menu` DISABLE KEYS */;
INSERT INTO `type_categorie_menu` VALUES (1,'Nourriture'),(2,'Boisson');
/*!40000 ALTER TABLE `type_categorie_menu` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `types_de_chambre`
--

DROP TABLE IF EXISTS `types_de_chambre`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `types_de_chambre` (
  `idTypeChambre` int(11) NOT NULL AUTO_INCREMENT,
  `Type` varchar(225) NOT NULL,
  `Disponible` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`idTypeChambre`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `types_de_chambre`
--

LOCK TABLES `types_de_chambre` WRITE;
/*!40000 ALTER TABLE `types_de_chambre` DISABLE KEYS */;
INSERT INTO `types_de_chambre` VALUES (1,'Chambre ventil√©e',1),(2,'Chambre climatis√©e',1),(3,'Suite',1);
/*!40000 ALTER TABLE `types_de_chambre` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `types_de_client`
--

DROP TABLE IF EXISTS `types_de_client`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `types_de_client` (
  `idTypeClient` int(11) NOT NULL AUTO_INCREMENT,
  `Type` varchar(100) NOT NULL,
  `Disponible` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`idTypeClient`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `types_de_client`
--

LOCK TABLES `types_de_client` WRITE;
/*!40000 ALTER TABLE `types_de_client` DISABLE KEYS */;
INSERT INTO `types_de_client` VALUES (1,'Particulier',1),(2,'Soci√©t√©',1);
/*!40000 ALTER TABLE `types_de_client` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-10-28 10:57:27
