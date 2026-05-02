// Function : FUN_40152040
// Address  : 0x40152040
// Size     : 46 bytes


undefined1 * FUN_40152040(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  if (8 < *param_2) {
    iVar2 = *param_2 - 8;
    *param_1 = 0x32;
    param_1[1] = (char)iVar2;
    memw();
    memw();
    iVar1 = (*(code *)&SUB_4008b3d0)(param_1 + 2,param_2 + 9,iVar2);
    param_1 = (undefined1 *)(iVar1 + iVar2);
  }
  return param_1;
}

