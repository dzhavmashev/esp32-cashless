// Function : FUN_40172640
// Address  : 0x40172640
// Size     : 58 bytes


void FUN_40172640(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 auStack_24 [9];
  
  auStack_24[0] = 0;
  puVar1 = (undefined4 *)FUN_40170220(0x10);
  puVar1[1] = 1;
  puVar1[2] = 1;
  puVar1[3] = param_2;
  *puVar1 = &DAT_3f425034;
  *param_1 = param_2;
  auStack_24[0] = param_1[1];
  param_1[1] = puVar1;
  FUN_40172558(auStack_24);
  return;
}

