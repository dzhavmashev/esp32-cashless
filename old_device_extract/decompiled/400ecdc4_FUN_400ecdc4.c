// Function : FUN_400ecdc4
// Address  : 0x400ecdc4
// Size     : 27 bytes


undefined4 FUN_400ecdc4(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  
  if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
    param_3 = (int *)*param_3;
  }
  uVar1 = FUN_400eccdc(param_1,param_2,param_3);
  return uVar1;
}

