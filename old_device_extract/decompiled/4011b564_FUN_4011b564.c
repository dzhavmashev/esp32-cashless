// Function : FUN_4011b564
// Address  : 0x4011b564
// Size     : 446 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_4011b564(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  undefined1 auStack_2c [8];
  undefined4 uStack_24;
  
  uVar5 = _DAT_3ffc6544;
  uVar1 = (undefined1)_DAT_3ffc6544;
  uVar2 = (undefined1)(_DAT_3ffc6544 >> 8);
  uVar3 = (undefined1)(_DAT_3ffc6544 >> 0x10);
  *param_1 = 1;
  memw();
  uVar8 = DAT_3ffbe0e0;
  param_1[1] = 4;
  param_1[2] = uVar8;
  memw();
  param_1[3] = DAT_3ffbe0e1;
  memw();
  param_1[4] = DAT_3ffbe0e2;
  memw();
  param_1[5] = DAT_3ffbe0e3;
  param_1[6] = 0x33;
  memw();
  iVar6 = _DAT_3ffbe0dc * 0x3c;
  param_1[8] = (char)((uint)iVar6 >> 0x18);
  memw();
  param_1[9] = (char)((uint)iVar6 >> 0x10);
  param_1[10] = (char)((uint)iVar6 >> 8);
  param_1[0xb] = (char)iVar6;
  bVar4 = DAT_3ffbe0d8;
  memw();
  param_1[0xc] = 0x36;
  puVar7 = param_1 + 0x12;
  param_1[7] = 4;
  param_1[0xd] = 4;
  param_1[0xe] = uVar1;
  param_1[0xf] = uVar2;
  param_1[0x10] = uVar3;
  uVar8 = (undefined1)(uVar5 >> 0x18);
  param_1[0x11] = uVar8;
  memw();
  if ((bVar4 & 1) != 0) {
    memw();
    (*(code *)&SUB_4008b530)(auStack_2c,0,0xc);
    FUN_4010173c(*(undefined4 *)(_DAT_3ffc654c + 0xc4),auStack_2c);
    if (uStack_24 != 0) {
      param_1[0x12] = 3;
      memw();
      param_1[0x14] = (undefined1)uStack_24;
      memw();
      param_1[0x13] = 4;
      param_1[0x15] = uStack_24._1_1_;
      memw();
      param_1[0x17] = uStack_24._3_1_;
      param_1[0x16] = uStack_24._2_1_;
      puVar7 = param_1 + 0x18;
    }
  }
  *puVar7 = 6;
  puVar7[1] = 4;
  memw();
  if ((DAT_3ffc6520 & 2) == 0) {
    puVar7[2] = uVar1;
    puVar7[3] = uVar2;
    puVar7[4] = uVar3;
    puVar7[5] = uVar8;
    memw();
    memw();
  }
  else {
    puVar7[2] = DAT_3ffc6540;
    memw();
    puVar7[3] = DAT_3ffc6541;
    uVar1 = DAT_3ffc6543;
    memw();
    puVar7[4] = DAT_3ffc6542;
    puVar7[5] = uVar1;
    memw();
  }
  uVar5 = _DAT_3ffbe0e0 ^ 0xffffffff | uVar5;
  puVar7[6] = 0x1c;
  puVar7[8] = (char)uVar5;
  puVar7[9] = (char)(uVar5 >> 8);
  puVar7[0xb] = (char)(uVar5 >> 0x18);
  puVar7[0xc] = 0x1a;
  puVar7[0xe] = 5;
  puVar7[0xf] = 0xdc;
  puVar7[10] = (char)(uVar5 >> 0x10);
  puVar7[0x10] = 0x1f;
  puVar7[0x13] = 0x2b;
  puVar7[0x12] = 0;
  puVar7[0x17] = 0;
  puVar7[0x18] = 0;
  puVar7[0x19] = 0;
  puVar7[7] = 4;
  puVar7[0xd] = 2;
  puVar7[0x11] = 1;
  puVar7[0x14] = 6;
  puVar7[0x15] = 1;
  puVar7[0x16] = 4;
  puVar7[0x1a] = 2;
  memw();
  memw();
  return puVar7 + 0x1b;
}

