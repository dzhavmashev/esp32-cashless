// Function : FUN_4017cb38
// Address  : 0x4017cb38
// Size     : 56 bytes


int FUN_4017cb38(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (iVar3 == param_3) {
      return 0;
    }
    iVar1 = FUN_401813bc(*(undefined1 *)(param_1 + iVar3),param_4);
    iVar2 = FUN_401813bc(*(undefined1 *)(param_2 + iVar3),param_4);
    if (iVar1 - iVar2 != 0) break;
    iVar3 = iVar3 + 1;
    if (iVar2 == 0) {
      return 0;
    }
  }
  return iVar1 - iVar2;
}

