// Function : FUN_401852a4
// Address  : 0x401852a4
// Size     : 85 bytes


undefined1 FUN_401852a4(int param_1,int param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    bVar1 = *(byte *)(param_1 + iVar3);
    if ((bVar1 != *(byte *)(param_2 + iVar3)) &&
       ((0x19 < (byte)((bVar1 | 0x20) + 0x9f) ||
        ((bVar1 | 0x20) != (*(byte *)(param_2 + iVar3) | 0x20))))) break;
    bVar2 = param_3 + -1 == iVar3;
    iVar3 = iVar3 + 1;
    if (bVar2 || bVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

