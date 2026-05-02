// Function : FUN_401417d8
// Address  : 0x401417d8
// Size     : 51 bytes


int FUN_401417d8(undefined4 *param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  char *pcVar2;
  int aiStack_24 [9];
  
  iVar1 = FUN_40141738(param_1,param_2,aiStack_24,1);
  if (iVar1 == 0) {
    if (aiStack_24[0] == 1) {
      pcVar2 = (char *)*param_1;
      *param_3 = (uint)(*pcVar2 != '\0');
      *param_1 = pcVar2 + 1;
    }
    else {
      iVar1 = -100;
    }
  }
  memw();
  return iVar1;
}

