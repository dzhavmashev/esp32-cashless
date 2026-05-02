// Function : FUN_40152018
// Address  : 0x40152018
// Size     : 38 bytes


undefined1 * FUN_40152018(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_4015b1d4();
  *param_1 = 3;
  param_1[1] = 1;
  memw();
  param_1[2] = *puVar1;
  memw();
  memw();
  return param_1 + 3;
}

