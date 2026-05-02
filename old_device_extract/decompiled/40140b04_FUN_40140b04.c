// Function : FUN_40140b04
// Address  : 0x40140b04
// Size     : 878 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40140b04(uint *param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  byte bStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  byte bStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  byte bStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  int iStack_24;
  
  memw();
  iVar4 = param_1[2] << 3;
  iVar5 = param_1[3] << 3;
  bStack_31 = (byte)(param_1[2] >> 0x1d) | (byte)iVar5;
  memw();
  iStack_24 = _DAT_3ffc5708;
  bStack_2d = (byte)iVar4 | (byte)(param_1[1] >> 0x1d);
  iVar2 = param_1[1] << 3;
  uVar6 = *param_1;
  bStack_29 = (byte)(uVar6 >> 0x1d) | (byte)iVar2;
  uStack_34 = (undefined1)((uint)iVar5 >> 0x18);
  uStack_33 = (undefined1)((uint)iVar5 >> 0x10);
  iVar1 = uVar6 << 3;
  uStack_30 = (undefined1)((uint)iVar4 >> 0x18);
  uStack_2f = (undefined1)((uint)iVar4 >> 0x10);
  uStack_2c = (undefined1)((uint)iVar2 >> 0x18);
  uStack_2b = (undefined1)((uint)iVar2 >> 0x10);
  uStack_28 = (undefined1)((uint)iVar1 >> 0x18);
  uStack_27 = (undefined1)((uint)iVar1 >> 0x10);
  uStack_32 = (undefined1)((uint)iVar5 >> 8);
  uStack_26 = (undefined1)((uint)iVar1 >> 8);
  uVar6 = uVar6 & 0x7f;
  iVar5 = 0xf0 - uVar6;
  uStack_25 = (undefined1)iVar1;
  uStack_2e = (undefined1)((uint)iVar4 >> 8);
  uStack_2a = (undefined1)((uint)iVar2 >> 8);
  memw();
  if (uVar6 < 0x70) {
    iVar5 = 0x70 - uVar6;
  }
  memw();
  iVar1 = FUN_40140aec(param_1,&DAT_3f42275c,iVar5);
  if ((iVar1 == 0) && (iVar1 = FUN_401408cc(param_1,&uStack_34,0x10), iVar1 == 0)) {
    if (param_1[0x35] == 1) {
      uVar3 = 3;
      if (param_1[0x34] != 0) {
        uVar3 = 2;
      }
      FUN_401436b0(uVar3,param_1 + 4);
    }
    *param_2 = *(undefined1 *)((int)param_1 + 0x17);
    memw();
    param_2[1] = (char)*(undefined2 *)((int)param_1 + 0x16);
    memw();
    param_2[2] = (char)(param_1[5] >> 8);
    memw();
    param_2[3] = (char)param_1[5];
    memw();
    param_2[4] = *(undefined1 *)((int)param_1 + 0x13);
    memw();
    param_2[5] = (char)*(undefined2 *)((int)param_1 + 0x12);
    memw();
    param_2[6] = (char)(param_1[4] >> 8);
    memw();
    param_2[7] = (char)param_1[4];
    memw();
    param_2[8] = *(undefined1 *)((int)param_1 + 0x1f);
    memw();
    param_2[9] = (char)*(undefined2 *)((int)param_1 + 0x1e);
    memw();
    param_2[10] = (char)(param_1[7] >> 8);
    memw();
    param_2[0xb] = (char)param_1[7];
    memw();
    param_2[0xc] = *(undefined1 *)((int)param_1 + 0x1b);
    memw();
    param_2[0xd] = (char)*(undefined2 *)((int)param_1 + 0x1a);
    memw();
    param_2[0xe] = (char)(param_1[6] >> 8);
    memw();
    param_2[0xf] = (char)param_1[6];
    memw();
    param_2[0x10] = *(undefined1 *)((int)param_1 + 0x27);
    memw();
    param_2[0x11] = (char)*(undefined2 *)((int)param_1 + 0x26);
    memw();
    param_2[0x12] = (char)(param_1[9] >> 8);
    memw();
    param_2[0x13] = (char)param_1[9];
    memw();
    param_2[0x14] = *(undefined1 *)((int)param_1 + 0x23);
    memw();
    param_2[0x15] = (char)*(undefined2 *)((int)param_1 + 0x22);
    memw();
    param_2[0x16] = (char)(param_1[8] >> 8);
    memw();
    param_2[0x17] = (char)param_1[8];
    memw();
    param_2[0x18] = *(undefined1 *)((int)param_1 + 0x2f);
    memw();
    param_2[0x19] = (char)*(undefined2 *)((int)param_1 + 0x2e);
    memw();
    param_2[0x1a] = (char)(param_1[0xb] >> 8);
    memw();
    param_2[0x1b] = (char)param_1[0xb];
    memw();
    param_2[0x1c] = *(undefined1 *)((int)param_1 + 0x2b);
    memw();
    param_2[0x1d] = (char)*(undefined2 *)((int)param_1 + 0x2a);
    memw();
    param_2[0x1e] = (char)(param_1[10] >> 8);
    memw();
    param_2[0x1f] = (char)param_1[10];
    memw();
    param_2[0x20] = *(undefined1 *)((int)param_1 + 0x37);
    memw();
    param_2[0x21] = (char)*(undefined2 *)((int)param_1 + 0x36);
    memw();
    param_2[0x22] = (char)(param_1[0xd] >> 8);
    memw();
    param_2[0x23] = (char)param_1[0xd];
    memw();
    param_2[0x24] = *(undefined1 *)((int)param_1 + 0x33);
    memw();
    param_2[0x25] = (char)*(undefined2 *)((int)param_1 + 0x32);
    memw();
    param_2[0x26] = (char)(param_1[0xc] >> 8);
    memw();
    param_2[0x27] = (char)param_1[0xc];
    memw();
    param_2[0x28] = *(undefined1 *)((int)param_1 + 0x3f);
    memw();
    param_2[0x29] = (char)*(undefined2 *)((int)param_1 + 0x3e);
    memw();
    param_2[0x2a] = (char)(param_1[0xf] >> 8);
    memw();
    param_2[0x2b] = (char)param_1[0xf];
    memw();
    param_2[0x2c] = *(undefined1 *)((int)param_1 + 0x3b);
    memw();
    param_2[0x2d] = (char)*(undefined2 *)((int)param_1 + 0x3a);
    memw();
    param_2[0x2e] = (char)(param_1[0xe] >> 8);
    memw();
    param_2[0x2f] = (char)param_1[0xe];
    memw();
    if (param_1[0x34] == 0) {
      param_2[0x30] = *(undefined1 *)((int)param_1 + 0x47);
      memw();
      param_2[0x31] = (char)*(undefined2 *)((int)param_1 + 0x46);
      memw();
      param_2[0x32] = (char)(param_1[0x11] >> 8);
      memw();
      param_2[0x33] = (char)param_1[0x11];
      memw();
      param_2[0x34] = *(undefined1 *)((int)param_1 + 0x43);
      memw();
      param_2[0x35] = (char)*(undefined2 *)((int)param_1 + 0x42);
      memw();
      param_2[0x36] = (char)(param_1[0x10] >> 8);
      memw();
      param_2[0x37] = (char)param_1[0x10];
      memw();
      param_2[0x38] = *(undefined1 *)((int)param_1 + 0x4f);
      memw();
      param_2[0x39] = (char)*(undefined2 *)((int)param_1 + 0x4e);
      memw();
      param_2[0x3a] = (char)(param_1[0x13] >> 8);
      memw();
      param_2[0x3b] = (char)param_1[0x13];
      memw();
      param_2[0x3c] = *(undefined1 *)((int)param_1 + 0x4b);
      memw();
      param_2[0x3d] = (char)*(undefined2 *)((int)param_1 + 0x4a);
      memw();
      param_2[0x3e] = (char)(param_1[0x12] >> 8);
      memw();
      param_2[0x3f] = (char)param_1[0x12];
      memw();
      iVar1 = 0;
    }
  }
  if (param_1[0x35] == 1) {
    uVar3 = 3;
    if (param_1[0x34] != 0) {
      uVar3 = 2;
    }
    memw();
    FUN_40143664(uVar3);
    param_1[0x35] = 2;
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    memw();
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

