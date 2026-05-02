// Function : FUN_4018ef70
// Address  : 0x4018ef70
// Size     : 1 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018ef70(void)

{
  uint uVar1;
  
  memw();
  uRam3ff5cc48 = 0x170433af;
  uRam3ff5cce4 = (*(code *)&SUB_40084594)(0x3ff5cce4);
  uRam3ff5cce4 = uRam3ff5cce4 & 0xffbfffff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c400);
  _DAT_3ff5c400 = uVar1 & 0xffff9f00 | 0x60a5;
  memw();
  memw();
  _DAT_3ff5cd04 = 0x51510556;
  memw();
  _DAT_3ff5cd08 = 0x51510556;
  memw();
  _DAT_3ff5cc0c = 0x1241fc;
  memw();
  uRam3ff5cc08 = 0x90b4d20;
  memw();
  uRam3ff5ccdc = 0x195c83c;
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c044);
  _DAT_3ff5c044 = uVar1 & 0xfe00ffff | 0x1fb0000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(0x3ff5c024);
  uRam3ff5c024 = uVar1 & 0xfffc01ff | 0x36800;
  memw();
  memw();
  _DAT_3ff5c094 = 0x1b8dd03;
  uVar1 = (*(code *)&SUB_40084594)(0x3ff5cc04);
  memw();
  uRam3ff5cc04 = uVar1 & 0xfffffe03 | 0x2c;
  memw();
  uRam3ff5ccd8 = 0x186;
  return;
}

