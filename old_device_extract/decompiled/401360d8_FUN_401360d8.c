// Function : FUN_401360d8
// Address  : 0x401360d8
// Size     : 57 bytes


undefined4 FUN_401360d8(undefined4 *param_1,undefined4 *param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_401355f8(*param_1);
  uVar2 = 0xffffb080;
  if (iVar1 != 0) {
    *param_2 = 3;
    uVar2 = 0xffffb100;
    if (2 < param_4) {
      *param_3 = 3;
      memw();
      param_3[1] = (char)((ushort)*(undefined2 *)(iVar1 + 4) >> 8);
      memw();
      param_3[2] = (char)*(undefined2 *)(iVar1 + 4);
      memw();
      uVar2 = 0;
    }
  }
  memw();
  return uVar2;
}

