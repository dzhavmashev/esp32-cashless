// Function : FUN_4018681c
// Address  : 0x4018681c
// Size     : 58 bytes


undefined4 FUN_4018681c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_3) {
      return 0;
    }
    bVar1 = *(byte *)(param_1 + iVar2);
    if ((bVar1 != *(byte *)(param_2 + iVar2)) &&
       (((bVar1 ^ *(byte *)(param_2 + iVar2)) != 0x20 || (0x19 < (byte)((bVar1 & 0xdf) + 0xbf)))))
    break;
    iVar2 = iVar2 + 1;
  }
  return 0xffffffff;
}

