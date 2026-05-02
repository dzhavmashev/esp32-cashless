// Function : FUN_400effd8
// Address  : 0x400effd8
// Size     : 32 bytes


uint FUN_400effd8(int param_1)

{
  int iVar1;
  uint uVar2;
  byte abStack_21 [33];
  
  abStack_21[0] = 0;
  iVar1 = FUN_400f1fcc(*(undefined4 *)(param_1 + 0x14),abStack_21,1,0);
  uVar2 = 0xffffffff;
  if (iVar1 == 1) {
    uVar2 = (uint)abStack_21[0];
  }
  return uVar2;
}

