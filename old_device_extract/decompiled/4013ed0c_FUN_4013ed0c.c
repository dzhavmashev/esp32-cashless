// Function : FUN_4013ed0c
// Address  : 0x4013ed0c
// Size     : 370 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013ed0c(uint *param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  byte bStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  int iStack_24;
  
  uVar3 = *param_1;
  memw();
  iVar2 = param_1[1] << 3;
  memw();
  iStack_24 = _DAT_3ffc5708;
  bStack_29 = (byte)iVar2 | (byte)(uVar3 >> 0x1d);
  uStack_2c = (undefined1)((uint)iVar2 >> 0x18);
  iVar1 = uVar3 << 3;
  uStack_2b = (undefined1)((uint)iVar2 >> 0x10);
  uStack_28 = (undefined1)((uint)iVar1 >> 0x18);
  uStack_27 = (undefined1)((uint)iVar1 >> 0x10);
  uStack_26 = (undefined1)((uint)iVar1 >> 8);
  uVar3 = uVar3 & 0x3f;
  iVar4 = 0x78 - uVar3;
  uStack_25 = (undefined1)iVar1;
  uStack_2a = (undefined1)((uint)iVar2 >> 8);
  memw();
  if (uVar3 < 0x38) {
    iVar4 = 0x38 - uVar3;
  }
  memw();
  iVar1 = FUN_4013ecf4(param_1,"_to_mpi",iVar4);
  if ((iVar1 == 0) && (iVar1 = FUN_4013ebb0(param_1,&uStack_2c,8), iVar1 == 0)) {
    if (param_1[0x17] == 1) {
      FUN_401436b0(0,param_1 + 2);
    }
    *param_2 = *(undefined1 *)((int)param_1 + 0xb);
    memw();
    param_2[1] = (char)*(undefined2 *)((int)param_1 + 10);
    memw();
    param_2[2] = (char)(param_1[2] >> 8);
    memw();
    param_2[3] = (char)param_1[2];
    memw();
    param_2[4] = *(undefined1 *)((int)param_1 + 0xf);
    memw();
    param_2[5] = (char)*(undefined2 *)((int)param_1 + 0xe);
    memw();
    param_2[6] = (char)(param_1[3] >> 8);
    memw();
    param_2[7] = (char)param_1[3];
    memw();
    param_2[8] = *(undefined1 *)((int)param_1 + 0x13);
    memw();
    param_2[9] = (char)*(undefined2 *)((int)param_1 + 0x12);
    memw();
    param_2[10] = (char)(param_1[4] >> 8);
    memw();
    param_2[0xb] = (char)param_1[4];
    memw();
    param_2[0xc] = *(undefined1 *)((int)param_1 + 0x17);
    memw();
    param_2[0xd] = (char)*(undefined2 *)((int)param_1 + 0x16);
    memw();
    param_2[0xe] = (char)(param_1[5] >> 8);
    memw();
    param_2[0xf] = (char)param_1[5];
    memw();
    param_2[0x10] = *(undefined1 *)((int)param_1 + 0x1b);
    memw();
    param_2[0x11] = (char)*(undefined2 *)((int)param_1 + 0x1a);
    memw();
    param_2[0x12] = (char)(param_1[6] >> 8);
    memw();
    param_2[0x13] = (char)param_1[6];
    memw();
  }
  if (param_1[0x17] == 1) {
    memw();
    FUN_40143664(0);
    param_1[0x17] = 2;
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    memw();
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

