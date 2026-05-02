// Function : FUN_4012d170
// Address  : 0x4012d170
// Size     : 36 bytes


undefined4 FUN_4012d170(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_401864ec(param_1,1);
  uVar2 = 1;
  if (iVar1 == 0) {
    iVar1 = FUN_401864ec(param_1,4);
    uVar2 = 3;
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

