// Function : FUN_400ebbd4
// Address  : 0x400ebbd4
// Size     : 39 bytes


void FUN_400ebbd4(short *param_1)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 2);
  if (((pbVar2 != (byte *)0x0) && (iVar1 = FUN_401844a8(param_1), iVar1 == 0x30)) && (*param_1 != 0)
     ) {
    *pbVar2 = *pbVar2 | 8;
  }
  return;
}

