// Function : FUN_40143738
// Address  : 0x40143738
// Size     : 67 bytes


undefined4 FUN_40143738(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  
  *param_3 = 0;
  do {
    pbVar2 = (byte *)*param_1;
    if (9 < (byte)(*pbVar2 - 0x30)) {
      uVar1 = 0xffffdc00;
      goto LAB_40143770;
    }
    iVar3 = *param_3;
    *param_3 = iVar3 * 10;
    *param_1 = pbVar2 + 1;
    *param_3 = (*pbVar2 - 0x30) + iVar3 * 10;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  uVar1 = 0;
LAB_40143770:
  memw();
  return uVar1;
}

