// Function : FUN_4016a944
// Address  : 0x4016a944
// Size     : 533 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016a944(undefined1 *param_1)

{
  char cVar1;
  char cVar2;
  undefined1 *puVar3;
  char *pcVar4;
  char *pcVar5;
  
  DAT_3ffca5b8 = *param_1;
  cVar2 = param_1[1];
  memw();
  if (cVar2 == '\x03') {
    cVar1 = (*(code *)&SUB_4008dae8)();
    cVar2 = '\x02';
    if (cVar1 != '\x18') {
      cVar2 = cVar1 == '\x1a';
    }
  }
  memw();
  puVar3 = &DAT_3ffca5b8;
  pcVar4 = param_1 + 0x20;
  DAT_3ffca5b9 = cVar2;
  do {
    cVar2 = *pcVar4;
    pcVar5 = pcVar4 + 1;
    puVar3[2] = cVar2;
    memw();
    puVar3[5] = cVar2 + pcVar4[3];
    puVar3[8] = 0xe2;
    memw();
    puVar3 = puVar3 + 1;
    pcVar4 = pcVar5;
  } while (pcVar5 != param_1 + 0x23);
  DAT_3ffca5c3 = param_1[0x29];
  DAT_3ffca5c4 = param_1[0x2a];
  DAT_3ffca5c5 = param_1[0x2b];
  memw();
  DAT_3ffca5c6 = param_1[0x2c];
  memw();
  DAT_3ffca5cc = param_1[0x32];
  memw();
  DAT_3ffca5d4 = param_1[0x3a];
  DAT_3ffca5d5 = param_1[0x3b];
  DAT_3ffca5d6 = param_1[0x3c];
  DAT_3ffca5d7 = param_1[0x3d];
  memw();
  DAT_3ffca5d8 = param_1[0x3e];
  memw();
  DAT_3ffca5e6 = param_1[0x4c];
  memw();
  DAT_3ffca5eb = param_1[0x51];
  memw();
  DAT_3ffca5ec = param_1[0x52];
  memw();
  DAT_3ffca5f6 = param_1[0x5c];
  memw();
  DAT_3ffca5fc = param_1[0x61];
  memw();
  DAT_3ffca602 = param_1[0x66];
  memw();
  DAT_3ffca606 = param_1[0x69];
  _DAT_3ffca5f4 = CONCAT11(param_1[0x5a],param_1[0x5b]);
  _DAT_3ffca5f8 = ((byte)param_1[0x5d] & 0x7f) << 8 | (ushort)(byte)param_1[0x5e];
  _DAT_3ffca5fa = CONCAT11(param_1[0x5f],param_1[0x60]);
  _DAT_3ffca5fe = ((byte)param_1[0x62] & 0x7f) << 8 | (ushort)(byte)param_1[99];
  _DAT_3ffca600 = CONCAT11(param_1[100],param_1[0x65]);
  _DAT_3ffca604 = ((byte)param_1[0x67] & 0x7f) << 8 | (ushort)(byte)param_1[0x68];
  DAT_3ffca607 = param_1[0x6a];
  memw();
  DAT_3ffca608 = param_1[0x6b];
  memw();
  return;
}

