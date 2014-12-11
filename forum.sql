-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 11, 2014 at 04:48 AM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `forum`
--

-- --------------------------------------------------------

--
-- Table structure for table `groups`
--

CREATE TABLE IF NOT EXISTS `groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(30) COLLATE utf8_bin NOT NULL,
  `description` varchar(256) COLLATE utf8_bin NOT NULL,
  `admin` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=3 ;

--
-- Dumping data for table `groups`
--

INSERT INTO `groups` (`id`, `name`, `description`, `admin`) VALUES
(1, 'Regular User', 'All regular users are part of this group', 0),
(2, 'Administrator', 'Message Board Administrators', 1);

-- --------------------------------------------------------

--
-- Table structure for table `imguploadtbl`
--

CREATE TABLE IF NOT EXISTS `imguploadtbl` (
  `imgID` int(11) NOT NULL AUTO_INCREMENT,
  `imgCreatedOn` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `imgDimension` varchar(100) NOT NULL,
  `imgMime` varchar(255) NOT NULL,
  `imgSize` int(11) NOT NULL,
  `imgData` longblob NOT NULL,
  PRIMARY KEY (`imgID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=17 ;

--
-- Dumping data for table `imguploadtbl`
--

INSERT INTO `imguploadtbl` (`imgID`, `imgCreatedOn`, `imgDimension`, `imgMime`, `imgSize`, `imgData`) VALUES
(16, '2014-12-11 03:36:09', '100', 'image/png', 8369, 0x89504e470d0a1a0a0000000d4948445200000064000000a60802000000a3a0bdbc0000200049444154789ced5d49901cc5d5ceacbdaaf775ba676bcd681b498c468316838830f26f0422ac1f6fc8f88083b089f0723011f8e28b035f7d70d807fb0081830870847db14518fdd80623631346424696048c34481a8d984db3f5cc7477757575adf91f9e552e7aad9ee901599aefd0915d95f92aeb552eefbd7cf912a10d78067652bb76eda2691a637ceddab562b1f829d6698dd8bf7fbf611808214110de79e71d8cf19123470e1d3a542a958e1f3ffec1071f40368661388e2b954ac16070cf9e3db3b3b357af5e4508618c09214ec2f98b10629c67d034fdfefbefd334bd63c78e9191914ffa15db87bd7bf7aaaa5a2c1693c9e43befbc33303070fcf871411010428f3df6d8d0d09061180cc3dc73cf3d972f5f2e954a0f3cf0c0238f3c5228149e7aea2941107ef0831f64b3d9d3a74f1f3e7c389fcff7f5f5cdcdcdfdf297bf440851ce331e78e0811ffff8c7870e1dfab45eb25d2897cb7ffbdbdf969696545545088d8e8e3ef5d45384105996bff6b5af1986118944bef295af442211c83f3c3cfcc4134f3cf6d86350f6cc9933972f5f9e9898387bf6ac24497ebfdfe7f341ceff30ab542a310c333c3c5c2a953ef1176c273efcf0c343870e6dd9b2e5ca952b70e5f9e79f7ff6d9679f7cf2c99191914824f2da6bafeddab5cbc94f08b12ccbb66d8410c7719ffbdce710428383837bf7ee1d1b1bbb76eddaf8f838e4c455cfba1d009dae5c2e3b57288a027688a2180e876559360c43d7754208c7713ccf13429a8ed4787878785deb7d3b81d9b367cfa75d87ff1a300821676abc2d4108a128cafd1763ec4e54e7af791d21c4104208210cc3b82956c0a1dee00aaa92506a263ca241c19aa4aa6522276d1846457ef7df6ae2d5171d30355fcc4dab1e9bababe57e5e75c2f95baf2a35b9e0ae9253996a5290a857a58a226e8ed47cbb462dab4126f7958abb356f354834ad4ae3c7ad9d14b0299fcfe77239e756777737e82d15c5354d2384c0aceaf09772b31ce04e13422626269c2bb95ccec9e35c44ae0feb60666606dabf9bac6ddb13131315142ae8385014851092cfe761ca87bba66996cb65f271288a52b30e15f584e696cbe57a7a7a52a9543c1e174551d7f58a7781b4a228c562d1dde70821ff517730c6a669cecece5a96655916c65892a49595155dd725495a5e5e8e46a3b3b3b3a15048d3b44c264351d4f4f434455120cef8fd7e45511886b12c8ba22886616459cee7f392242d2c2c5014158fc74ba5926559a3a3a37ebfbfa7a76771715151145114f3f93c4dd38410dbb6298aa228aaa7a70763bcb4b4a4ebba6ddb0cc3608c6ddb86af9dcd664551d4340d211489444cd32c168b8542211008188641d374b95c06e1dbdd319d5f4dd396979755550d0683a86a9480343cabe262e5a06e9a26b488dedede6c361b0e872549824f47d3b4dfefcfe5723ccfdbb6ad699a6559a55289a6e9542a25cb723c1eb72ccbe7f381b0a7280a4dd38aa24892248aa22ccb3d3d3d08212743b158ecededc51887422184104551a9542a1c0e23844aa592288a14450982c0719caaaab22c0b824008812f019f331008288ae2f3f908219148a45c2e439f9224099a4ccd81d2b66d9ee74551acd93f003e9f0fc8badb2c0d7216455118638aa21445e1384ed775555533994cb158e479deeff7dbb61d0a854cd34c2693baae731cc7308caaaa200d134282c1e0d2d2523299c418330c035c2e954a909024091a66341ab56d5b9224d334a3d1e88d1b37a0c5810a268a22cbb21cc7b12ccbb22c7c5ebfdf4fd3b42008344d330cc3308caeebc04ad334298ae2791ebe9cdfef370c43100486612003b0c6691a84105996755d075e170a854824c2301feb5e90c8e5729aa6395ae1bfef7ef39bdf8476ee161de073b9cb933a53989359d7758c31cbb21fa3ee4162f0285eb444ca0d30d7385cb06ddb344d273f74f09ad448d5bc5983a90821bfdf5f5d8f7a5584cc3ccfd77b817a05abf334cedc12a97a17298ae238ae01058735d5b5fa37b39cb67afb81d417156ba2416606dd9c079b36f2ff52501445aa045477c7af9057abc70427cd8ccd2384b0db647a670057259c74e52d8c513a843146f8763569b517adf4e30d6c6003b70628bac6459abe837a735d835f35a2290e54499ac134831142348d629d6c9362b7115a68172c4f6dda1eeecbf450ac2aab857cbea4148ca9cb65d3b83d05b46ad4ea5ab5c0b0d4c1fbb7f564a23467e8966a583ac5604ea47c613abf6890db56feff18bc326b604f22dac1e40a794c59ba6918966559b6ae598244331c2e64cd75ade52d024f6316cb51f14ec1b00cb958322ddbb6896d13cbb60ddd460805e30cc3dd11c3bc2766f1124d5118211c4f8410c6046182304248f033362108114eb82398d5a41b322c95ecf2699a290488ae59a6699b866d18a66958866199baad972d4327ca8a1d4ffad5d26d3e78356156ef96d0a61d3ec334621d3e41a0314286611886615916b1092136c28420e2f78b9bb6074a254dc95b9f4cbd3f1534eb8694ad1965828965d91c47893eca17a0251f234a342f502c4b81e4852954d655823fd6aebababa366dda5473ed96a6699a6ef29d82c1606767a7f737191818804447470742481084603008e976a1f99885114288106283d5bee21e8531852b2c1b0821d4d7d7170c0655551d1e1e8ec7e308a144222108c2a64d9b789ebffbeebb07070711425d5d5de17098e7f98e8e8edede5ebfdfdfdbdb0bfc05db7f381c1604211008c07a4f229148a7d3b1582c954a818355341a059ec6623178f4f6eddb1142c160309d4e43ba5df030c003b710420411f231766184618508571931565656e2f1b82449e7cf9fdfb973a7dfefefeaea3a70e080a228fdfdfd8542a15028ecdcb99365d9bbeeba2b1e8ff7f5f54992343434c471dc962d5b8048241219181820840c0d0d2184060707f7ecd963dbf65d77dd85311e1e1e0e87c39b376f0e04027d7d7d6d6248233461162104ff9b15d8b50a79131821441046d5223c21e4d4a953e57279dfbe7d8b8b8bc3c3c3e3e3e3a3a3a33d3d3d84104dd3344d8bc562a1504896658aa29697971717179796961617171d1b793a9d2e140ab09216894472b95ca9549a9f9f87f5cd72b91c8d460541e079beda01af55ef0a2f68deb2084218219aa208812536b725b1aefb822449070e1ce8ecec9465797c7c3c1c0e170a85bebe3e58585455b5b7b7f7faf5ebb0f6e52c0b57e0d2a54ba228320c532e97298ab2accad963767616566860090790cbe5eebefbeeeddbb7cfcccc78e2816734918f4231ae6b0bb738636c1d8c302c46c4b66ccb326dd3b22c8b58966d98966593951992e8e226461525ff9f311e16486cdb4ea7d39148e4d2a54b08219aa6e19dc1150f0ce48ef1bbc219c6fdd7c95ff1eb3cc5f1ed4337edee4ea97631ab89e93dbfa4e797f44084a3699a101b2172b3cbc182dabf8730a5602c4e6915659d955e8cf1e8e8285c745a07bc83db8fa1e2b7e2af3bbffbd7798a9b294ebabdab569e744343b32cdb62384c518420641362dbc4346dd3b275cdcecd5b85c546e2952ccb6daaeda70caf8a7461d94018d13c99bea64c5f5517a63544285ea01726f5951bb7b320ea460bc63f9aa6fc7e1621a4ca76b94830a6022196e5ef08ad10d002b38a39bd5cb654d9baf9d7d0ca962adfd6dae0ad8c743a1d08043eed5ad485d731ab5580b708f80985c3e1582ca6aaaa6ddb9d9d9d82205896158bc5c0df2a9d4e3bb752a954a954b26d3b954a81e7df3a556f75582f66f5f7f79ba6198fc71986d9bb77efcccccceeddbb25496259b6a7a747d3b47dfbf64d4e4ef6f4f4c8b27cd75d770502019aa62391c8f2f2f2d0d050369bddb66ddb8d1b37d6a97aab430b63d6aa91cfe7e7e6e61042a150687c7c7c71711121b4b2b2b2b2b2120c0663b118cff3a150e8faf5ebd96c96e7f96030984c26dd6eb2b708d68b592b2b2b3b76ec00fd361a8d0e0d0d298a323535b57ffffe4c26e364134591e7799aa6a7a7a7f7efdfdfd3d3532e975756566cdbae566e6e67300c0376ab83070f824760381c4ea7d3070f1e04cf478410c6d8b16d417e7000aaf020bc8300f62c84104551994cc6f9bb810d6c002154cf44d360d3d31d829ae68a1acc3a7cf8f06f7ffbdb969c566f33589675fffdf73b66250735ec59e170d8edd85c8d56fd7f1b8034dbfdb78ac755d3f4f214371886a9a975d5ee6eadf2a2c25cd7388f7752f58ab4450daa26e2be529303b59955b1450ad56187db165af16cf78618278f97ea3658686889543d546c7daafe240d48d5362b576fd6abb909c24bb696b60456ffae9a94470a0d5ea11aab99f55aea748dbf794b1daad5dee7b10ede9f55b71bbaff9aa6f9c20b2ffcf4a73f7df3cd375f7cf1c55557ab41d49613274e2c2f2f0305c8e691e63ffef18f6bd7ae5557e6a5975e6a50cfa6a8d9beeaaeeeb8e9320cf3f8e38ffffce73f3f74e8d0b7bffded999999af7ffdebafbcf2caf6eddb8f1c39f2fcf3cf178bc5c3870fbff5d65ba228a652a9ebd7af673299a9a92984d077bef39db1b1b13ffff9cf5d5d5dafbefaea4f7ef2135555272626262727198681f5d777df7d776c6c2c1e8f9f3d7bb6b3b3f38f7ffce3f7bffffd37df7c73ebd6ad478f1e3d75ead4d9b3673ff399cf9c3c795210846ddbb64d4e4e6edebc797a7aba5c2e777777dbb6fda73ffd29994c66b35945518e1e3d7ae2c489f1f1f1aeaeae8b172f3efcf0c35bb66cf9ddef7e373939f9d0430fbdfefaebe9749aa2a8f9f9790814f2f4d34f57ef4269a165d5631cc678f3e6cd8944e2c489130cc364b35984d0f2f2f2b163c7de7aeb2d8cf1c8c8c8850b171e7df4d1f7df7fffd2a54baaaaeaba2ecb722814ba7af5ead6ad5b138984aaaad96c766a6aeac68d1b4f3cf1c46bafbdc630ccdd77df2dcb723018bc72e5cad6ad5baf5ebd8a31ce66b3849042a12008c2f9f3e7138984dfeffff0c30f8f1d3b76fefc7908f3410829954a3ccf5fb870a15028dc77df7dafbffefae0e0605f5f1f1817a1e6636363dffad6b7ce9d3bf7e0830f5ebf7e7d7676f64b5ffa92cfe7334db3a679a385d9b066e1bebe3e42487f7f7f7777f7830f3e68db766f6f2f424896e5e3c78f1f3c78b0542a757575eddbb7efd7bffe752a95022706d85a27cb726f6f6f2291989b9b4ba7d357af5ee579deb2ac175f7cf1e8d1a3144565b3598ee3205b4747c7e6cd9b298aeaededfdcb5ffe4208b12c2b9148bcf7de7b9aa6452291dffce637fbf7efd7759da2a86432e9f7fb61536c7f7f7f2412b9f7de7b474747298a525515369abef9e69b0303032fbdf4d28103074e9e3cb96ddbb64c26238a624f4f4f7f7fbff785fe1afc3b76ecd8b3cf3e8baa364d01dc9337a45f7ef9e52f7ff9cbce957ffdeb5fefbefbeed1a34761936fc564ef2678e2c48923478e8035a6a600e9ae43b1583c75ead4e1c387fffad7bfeedbb72f140a55d4adb12c5af13a159dae3affc30f3ffccf7ffed313b39e7bee392f9c5e0f517e3d48ad82f8912347aa99557b80affe38a74f9fce66b3f7df7fffabafbe3a3c3c0c4b0ce170f8cc99330f3df4d0d5ab57efb9e79e35d6af1e564daa2d5c73a389af8343faef7fff7b241299989880110a634c51547f7fffd2d2d2caca0a78a679a95fe3bf0d0aae859417e25eeed61de02bd49a6432393636363a3a5a2e972dcbeaeaeaca64327ebfdf34cd8f3efae8dcb9738d6be6a49bbe4fc573bd936ad7dede06779bb42ce031c6f81bdff8866118a2282a8ac2f3fccf7ef6b3279f7c321a8dde77df7d814000760daf5afdaeb8d2c62edcf8d1ad3ea5793784aa330c03d316843078fae9a7e12f04dd80d008d51a69753771ff367d990677abfdb96acedad595713ebf3b9bfb5683ba79154a2bca731ce79e83abf37b215b8d5537a86a59a97127751b1baa73d6ab7fa396d5d876d1c090d2e062c527f552b62da49ace245e54d1462dcb6dd9f0dec96be671bf583d525e6c18f54835608497ea79ccd08859a07699a609cec5359f8d105a5c5c0483413d22b05e0f69cbb2200c904777c07c3e5f917048a18606bc9191919a2a71d3c6bbca968510b26dfbc2850b67cf9eb52c6b64644496e56c36abebfaf2f2f2c58b17354d9b9d9d9d9999999a9a5255757c7c7c7a7adab2ac8b172fe672b942a170f1e2c5a5a5a58f3efa6861610182f1168bc5dffffef7a6698e8c8c64b3d92b57ae64b3d972b90c7edd4b4b4be572f9830f3e8078ac8661bcfcf2cb103a6669690922fac2cb8c8d8dcdcece2e2d2dd9b63d3737f7ca2baf8077f7f8f8f8d4d4d4e4e4e4c2c2424b628a1734990d21be91dfefbf74e9d2ce9d3bcf9d3b47d3f4b66ddba6a7a75555e5797e7171b1afafefca952b0b0b0b8aa22c2e2ececcccecdcb9f3bdf7de43080d0e0e5eb9728510f2f6db6ff33c9f482430c6fdfdfd2097bdfdf6db8220489274f2e4c923478e7cf8e18708a170380cee0ea2289e3f7f7ef3e6cdb02a353f3faf695a3018b46d7b6161c1b6edf1f1718ee3868686ae5fbf0e1b1472b99c2ccbe5723993c9546f44a9d9255be257f3d9301e8f2793495114a7a7a7699a364d737272122104f1a7c0660421b7f2f93c44f09a9e9ec618d334edf80c0502011062811d1cc7d9b60d9b4c1042c16010f65cc08e015114a160301804671b20128944e6e6e64cd3140461797959d7759ee7c7c7c721c493a6691cc7e5f37908e55bbdf4593d213448d4447345da344d506e72b95c3018b42c4b5555e0146c855014055a5fa95482f060f97c3e1008cccccc5cbb76adb7b71738522e97a15d58960531b0288a02531404c0320c03630c0d241c0ec3dbeaba0e021d6c2cd0751d16a98ac522c4d882e06fb66dd334cd719ca2281051cbb2acb578973cfcf0c367ce9ca9b8c8400c4000f0d51d7ccbfd173616d134cdb2ac7b3870226d398970386cdb767777773299e4791e320367214a1dba19422a180cc25d9ee79d9a44a3518738c77130b5437e27f09413b4ca8927edd401f2c3be817a469ba66059169ee5cecfb8031003dcba8bbb7dbac305c1d606a0e5a41dd8b6fdc61b6f0c0e0ea6d3695447e4f9e0830f76efde5d5dcb6a9353cd5b6bd7871a13310c030400371ad9e031c62b2b2be7ce9d2b97cb9148a4bbbb1b62414298b96c364b51d4ae5dbb26272759962d954a9224c12893c9644cd39c9e9e5e5858505575707090a6e9b1b131d882430881ed38ab7ec3b573b071a97a235773d1a1a7a7271a8deedebd7b7e7e1ec2389aa6b96fdfbe6030180c06a7a6a6f6eeddab691af88e5ebf7e3d1008442291542a6518466767e7dcdc1c740d88926d18c6f0f03044b6af2907a15a7253cd97599d52e534d89a2db766da4113d101f6ae4153eaeeee1645911092482410429d9d9d18e3783cfede7befc1120b42c8e7f381d92b994c9aa6592814eeb9e79e62b108c61c86614070ebefefafa79ad57c372f7a72e317a9d6eadd897a2cab4013dd1002410277d2e9348c41804d9b3601ddfdfbf743a25c2e2712896834dad1d1e18c684e6df6efdf8f109a9e9eeeeaea82ae54c1889ab5f462a2a8a8b3c79cab40f3e5fb06702b8f08215114abb7d956e40131a2fa290d9e5841a166c106b73c262a48d5accf9deeb4d6123698551b35bbf3adc2ac368e35eb376cdd2acc6a80b5bfbc47d5cf8d16c62c2f624ee36c1eebd712235ae55adb9b98a7a530ef6860e15dc5abd694571b3fa52d685982f7283d786144f564dcaa05d90ba9556b8bde4dcf4d5a56b506504ff6ad69dbad47aa8114ea26e5a565ad51a3764bbc6b55775015531ce09b8715785744db6836686a7ea95907c3b68f4f5edb1fef504cc3b0edc1488cc5547565ea55cf6b48e57a1fb9a5e2357597c6ea8e475235bb52454bc118ffdff4f57db1e4cb93d7c60ab9e158726f2c593d1135a84693d59da6575a0269e8b9dda00e35fb786352350b46386124b784114e8ad2bc5ab2ec8fc537695a99462dabba36ee2b2dbd7675c1560766b74e5e8f14aafa9c156df650aaeb7261e5c1ce4cc934688a3288cde316363eb7b0228d3c0c81f5aebb07beb537cf06a49a7ec2edc108c658bcb935b4257975f55687566d068d33b7fac4a6a4566d7e685093ff0275e7d6411375a7b1acdc467567eda4bce45fe308d044286ddc3baa67ee9ac3763df9b6c173ebe56940caa356e0e56e0bea0eb86c781986bcd4af6231a682424ba2696352ab463505dbb66b1e395afb49ee938ce010d381811d08a10b17cecbb20c9e1a3ccfc3f6048aa2fc7e3fc6181650599685d3c66459f6f97cb66dc3158c31ac12c3af6ddb4b4b4b70d81542886118200b6bba40816198e5e5e54422e11c30abaaaacfe75314a57a51af8d2084d43cc5b7f66c085e4100cbb224c967183aacbc3bae3f10da1598053e102ccb1a860147ad89a258281480054e11c8006938468ce33838c20a2104875d114220bc1facd43b87b5618ce18032f0005e5766d583a7369c4aa5388eb36cbbacaa4b4b4b70d169590d0ac26e90d5d54c100438647075c5d7039e4487858545bfdf4f6cdbedb4665956d3375935a71042708ee1aa8baf073c09fbbb76ed8a46a3e14804b93cf0a0d7ac63d536b0810d6ca00a9ec62c96657b7a7bfd3e9f3bb45ccd5d15b7379a5b4a5996fddcfffc8f244918e3f9b9f9d3a74f01834086ba8d0f46ac46f396d5dfbfb9bba7fbe41b6f64b3d91d3b762c2c2c80740bfe43e0cc994aa5344d83e35a6ddb068747886b2c08021c180b57209c98288a20c70a8200ae4820d3c3b66796650541088542f8665465084806c7ac628cc1bf16f2c3230821e0470abbaec0b912b2b531bc72f39625cb058c703a9d967c3ed3326b0613079508631c080440e38176373b3b0bfea5c00ec3304cd384e36a5996053665b3d940204008a169da300c3824d5344de08ecfe773fc931c6d09b4b9f9f9f964326918066c2482c39b1142a228aaaa1a8fc7e18c64cbb21c417a8d68deb214450987c35bb66c8d46a2a3a3a3b3b3b370dd6959f866d06c38c319fc8e812986614422115555dde72883d06fdb361c87e11c965b2e97c17d92a6699066c1bbd5b66d5dd7a1cb838e056d4d5114e01d9cc40d672783eb34cbb29aa6c1765b8cb143f093802008fffbc8239ffffce7ddcee5700271e382d0e89ad29724a9a5fa8442a1968a343d2fc32b1d2f994cd3f449d28d1bb38eff3e72b5aca6659bd27787bef70268bcdef3b76bcaf6ca7242c8f2f292fbcd3d32eb76825766a9aa5af1311b300b067898b99cafca715c858902b64854db2dfc7ebf7b8881634f82c12021449224d8fa821082e9af419d5996ad68532ccb3a27bdaf025e57a41bb4208ee3a2d12858b20cc3902449d334d861821082f195dc04cbb2aaaa4a92343f3fdfd1d1a1aa6a201080ad3c9aa60982303737170c06812908a1959515411030c670743c54a3502820847c3e5f2c16d3348da669b8ce300c38999ba6298aa2a6693015c02e9f8585856432093b679c67b5d443dbb0ba03b3a1288ab66dc32cee7c3db079f13c2fcbb2288a1863d88e045584f74408e9baae280a985b11428e6c057319d80881a6aaaaa15008f6a2300c030154801aec28a2695a92244110288a02b90c76af413d6152763feb1382331b721ce7de560e82123428478084bf20228aa208deddc011b8084580025c8fc562f03e4e7c5c782eb003dddc06e408ba154f74245298911d7f722773d3a97c5d9875e7606391b5057c42ccaad82ae934492fd1635b1229d7351c6d7bfa512814027d15009351a9540215178e6d82fdcf814040d7f5743a3d3131914aa51042854201d43d9819cbe5b22449a006828a130e87612a80bdc0f97c9ee77908f10da203cc77a0990702010881b61e6803b3689a06d302480f9148a45c2ec331038aa2c0210c8410d8eb44d37430182c168b8410d8ba2a8aa2200830d34992c4dc84aeebe1701804085825023b04ec0b86b6e9cc68300b03bfd6fe46f5d09e9605e10c9c43bd745d2784e8ba0ee2826559e572196c09b0d5175e12b46284101876808e6559a02483d0a0eb3ac3308410d87dcc711c94c2181b86015b860b85022104ac3dad6a4e9f10bccc86a150685d674cbfdfefdeb67ceba2e60ef70d6c60031bd8c0ad02afc231a8c76e8386135f745dea754bc2eb7436303000fe6c0ec060b00e55ba75d1bc6551142508a2691a8a52dcb9731741a828cbc86529e5384e1004bfdf1f080424498284a228b1580c56626035100c9b701636189860690f6c610821706c03891f32747474148b459fcfe71879f0cd382b60848152b08008c4212a109c3e6d5956341a852525c80fb65388f8425114186f63b1182c083595fe9b4b8c8944a2bfbf7f6c6c8c2084f1c79c0201f060387297a669b7012b1c0e2b8a128944288a9265191260414d2412344dcfcece0a82108fc761a1aca3a3c371fc05a11f2104aa25c8faa552092cabee35314dd34451946599a6e96c361b8fc78bc5a26118e1701818ea44d121ae8023a55229128940688e64328931be71e346637e356f59baaea75229d33433994c369b9d9f9bfb379b6fb62cdbb683c120e87d8e3a0ddf132104eba6b66d83d724a884aaaa82dd128212813288105214c5344d679d9165598866e4a838a081c2a22470106ed9b62dcb3284a9864546704905d50a2c8e08215882942409961731c6a04e4174718870b656701c3f3434944824dd17db6bfc6b75e970d58f80c5f3d551f0341b42c79624d16dfd8046d4aed9f0135080e111b07cbd3a0a5ea7b3442251d1b2201edaea9e7a9b836118fa0eb3b86f60039f14bcaa3bb1580cfc9efe53b24dae29ff45f0b42abb7bf76e9a6630469aae5fbc79760e9871d7d5e67dabc1d36c188dc6ce9f3f77eedcb9782c567d97a6e98e8e0e584dc018fb7c3e704e73646548806b2014a9d8dfe564736cc43577a3ba093a8f70fe42d9ea826d84a7096e65a56ee8648410c6182c10b1580c962a30c69148041c346edcb801c16861210774147819b0644c4e4e767777832f89aaaae0c7e0f3f9204020288c8b8b8be9741afc57614d08d67842a150a954d2751d9a399c8b0b2ae4cccc4c1bd8f3713467567777773e9fdfb46913424810c4eeeeeee9e9e98a3ce0f0592a950a8502bc2d2816a0e8c0020fc88460a880ceebc88790a1582c02df41c501cab95c2e1a8dc207009a84108ee3c0053297cbc12d70ae8495a1f513009b37d781810188c70ad034edf2e5cba8156736d821b8ba0c2ccb821f6d53221bd8c006ee04ac758a4da552c78e1dfbc52f7ed196da2084fc7eff17bff8458cf11ffef0078fa71178c181030742a110428810f2f6db6fafce74b57a233acff3dffbdef71e7ffc717086690b188679e69967ce9c3973faf4e9679e79c63db1ac118f3efa289c64d0dbdbbb67cf9e7691f584cd9b373ff7dc735bb66c4108fdf0873f6c17d9e1e1e12f7ce10b907ee8a1870e1c38d02eca4e253ffbd9cfde7befbdab23b2ca9635391058c6020000006c4944415439f9eebbef7ef5ab5f75c76e5f3b16171733990ca43399ccc2c2421b89af1dab34511986f1ab5ffd2a91487cf7bbdf6d63ab9e9e9ecee5723ffad18f10421313131f7df451bb28c7e371685cf178fc85175e6817d996d1dec685100295a5bd3437b0810ddc1ef87f7d21825f7aa5a0b50000000049454e44ae426082);

-- --------------------------------------------------------

--
-- Table structure for table `logins`
--

CREATE TABLE IF NOT EXISTS `logins` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user` int(11) NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `ip` varchar(15) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user` (`user`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=8 ;

--
-- Dumping data for table `logins`
--

INSERT INTO `logins` (`id`, `user`, `date`, `ip`) VALUES
(1, 9, '2014-12-10 00:59:19', '::1'),
(2, 7, '2014-12-10 00:59:42', '::1'),
(3, 7, '2014-12-10 02:06:04', '::1'),
(4, 7, '2014-12-10 02:10:40', '::1'),
(5, 7, '2014-12-10 02:10:47', '::1'),
(6, 7, '2014-12-11 03:06:52', '::1'),
(7, 7, '2014-12-11 03:37:02', '::1');

-- --------------------------------------------------------

--
-- Table structure for table `posts`
--

CREATE TABLE IF NOT EXISTS `posts` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `topic` int(11) NOT NULL,
  `user` int(11) NOT NULL,
  `text` blob NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user` (`user`),
  KEY `topic` (`topic`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=4 ;

--
-- Dumping data for table `posts`
--

INSERT INTO `posts` (`id`, `date`, `topic`, `user`, `text`) VALUES
(1, '2014-12-10 00:59:33', 1, 9, 0x48616c6cc3a5),
(2, '2014-12-10 00:59:51', 1, 7, 0x48656a73616e),
(3, '2014-12-10 02:16:07', 1, 7, 0x546869732069732061206c6f6e67657220706f7374210d0a0d0a546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f73742120546869732069732061206c6f6e67657220706f737421200d0a0d0a0d0a56657279206c6f6e672e);

-- --------------------------------------------------------

--
-- Table structure for table `tables`
--

CREATE TABLE IF NOT EXISTS `tables` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `name` varchar(30) COLLATE utf8_bin NOT NULL,
  `user_group_viewing` int(11) NOT NULL DEFAULT '0',
  `user_group_posting` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=7 ;

--
-- Dumping data for table `tables`
--

INSERT INTO `tables` (`id`, `date`, `name`, `user_group_viewing`, `user_group_posting`) VALUES
(4, '2014-11-29 06:55:56', 'Announcements', 0, 2),
(5, '2014-11-29 06:55:56', 'General', 0, 0),
(6, '2014-11-29 06:55:56', 'Trash', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `topics`
--

CREATE TABLE IF NOT EXISTS `topics` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `table` int(11) NOT NULL,
  `name` varchar(35) COLLATE utf8_bin NOT NULL,
  `user` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `user` (`user`),
  KEY `table` (`table`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=2 ;

--
-- Dumping data for table `topics`
--

INSERT INTO `topics` (`id`, `date`, `table`, `name`, `user`) VALUES
(1, '2014-12-10 00:59:33', 5, 'Hej', 9);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(30) COLLATE utf8_bin NOT NULL,
  `password` varchar(32) COLLATE utf8_bin NOT NULL,
  `email` varchar(50) COLLATE utf8_bin NOT NULL,
  `default_group` int(11) NOT NULL DEFAULT '0',
  `avatar` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`),
  UNIQUE KEY `email` (`email`),
  UNIQUE KEY `avatar` (`avatar`),
  KEY `default_group` (`default_group`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=10 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `name`, `password`, `email`, `default_group`, `avatar`) VALUES
(7, 'Oskar', '49174e529aa19bf1de200d3594bba6ff', 'oskar.danielsson@hotmail.com', 1, 16);

--
-- Triggers `users`
--
DROP TRIGGER IF EXISTS `addNewUserToRegularUserGroup`;
DELIMITER //
CREATE TRIGGER `addNewUserToRegularUserGroup` AFTER INSERT ON `users`
 FOR EACH ROW INSERT INTO usersgroups (userid, groupid)
VALUES (NEW.id, 1)
//
DELIMITER ;
DROP TRIGGER IF EXISTS `users_avatar_after_update`;
DELIMITER //
CREATE TRIGGER `users_avatar_after_update` AFTER UPDATE ON `users`
 FOR EACH ROW IF NOT (NEW.avatar <=> OLD.avatar) THEN
	DELETE FROM imguploadtbl
	WHERE imgID = OLD.avatar;
END IF
//
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `usersgroups`
--

CREATE TABLE IF NOT EXISTS `usersgroups` (
  `userid` int(11) NOT NULL,
  `groupid` int(11) NOT NULL,
  `moderator` tinyint(1) NOT NULL DEFAULT '0',
  UNIQUE KEY `unique` (`userid`,`groupid`),
  KEY `userid` (`userid`),
  KEY `groupid` (`groupid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `usersgroups`
--

INSERT INTO `usersgroups` (`userid`, `groupid`, `moderator`) VALUES
(7, 1, 1),
(7, 2, 1),
(8, 1, 0),
(9, 1, 0);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `logins`
--
ALTER TABLE `logins`
  ADD CONSTRAINT `logins_ibfk_1` FOREIGN KEY (`user`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `posts`
--
ALTER TABLE `posts`
  ADD CONSTRAINT `posts_ibfk_1` FOREIGN KEY (`topic`) REFERENCES `topics` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE,
  ADD CONSTRAINT `posts_ibfk_2` FOREIGN KEY (`user`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE;

--
-- Constraints for table `topics`
--
ALTER TABLE `topics`
  ADD CONSTRAINT `topics_ibfk_1` FOREIGN KEY (`user`) REFERENCES `users` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE,
  ADD CONSTRAINT `topics_ibfk_2` FOREIGN KEY (`table`) REFERENCES `tables` (`id`) ON DELETE NO ACTION ON UPDATE CASCADE;

--
-- Constraints for table `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `users_ibfk_1` FOREIGN KEY (`avatar`) REFERENCES `imguploadtbl` (`imgID`) ON DELETE SET NULL ON UPDATE CASCADE;

--
-- Constraints for table `usersgroups`
--
ALTER TABLE `usersgroups`
  ADD CONSTRAINT `usersgroups_ibfk_1` FOREIGN KEY (`userid`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `usersgroups_ibfk_2` FOREIGN KEY (`groupid`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
