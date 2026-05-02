// Function : FUN_40154d58
// Address  : 0x40154d58
// Size     : 40 bytes


int FUN_40154d58(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (*(code *)&SUB_4008b33c)(param_1,iVar2 + 0x3ffbfc5a,2);
    if (iVar1 == 0) {
      return iVar2 + 0x3ffbfc5a;
    }
    iVar2 = iVar2 + 5;
  } while (iVar2 != 0xe6);
  return 0;
}

