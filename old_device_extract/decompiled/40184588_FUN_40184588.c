// Function : FUN_40184588
// Address  : 0x40184588
// Size     : 40 bytes


int FUN_40184588(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar1 = 0;
  iVar2 = 0;
  iVar4 = 1;
  do {
    pbVar3 = (byte *)(param_1 + iVar1);
    iVar2 = (*pbVar3 & 0x7f) * iVar4 + iVar2;
    if (iVar1 == 4) {
      return -1;
    }
    iVar4 = iVar4 << 7;
    iVar1 = iVar1 + 1;
  } while ((char)*pbVar3 < '\0');
  return iVar2;
}

