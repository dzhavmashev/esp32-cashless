// Function : FUN_40151fe8
// Address  : 0x40151fe8
// Size     : 48 bytes


undefined1 * FUN_40151fe8(undefined1 *param_1,byte *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)*param_2;
  uVar2 = 8;
  if ((8 < uVar3) || (uVar2 = uVar3, uVar3 != 0)) {
    *param_1 = 1;
    param_1[1] = (char)uVar2;
    memw();
    memw();
    iVar1 = (*(code *)&SUB_4008b3d0)(param_1 + 2,param_2 + 1,uVar2);
    param_1 = (undefined1 *)(iVar1 + uVar2);
  }
  return param_1;
}

