// Function : FUN_4012d814
// Address  : 0x4012d814
// Size     : 42 bytes


int FUN_4012d814(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x44) + 0xa4);
  iVar1 = FUN_401355f8(uVar2);
  iVar3 = -0x6c00;
  if (iVar1 != 0) {
    iVar1 = FUN_40185ad8(param_1,uVar2);
    iVar3 = -(uint)(iVar1 != 0);
  }
  return iVar3;
}

