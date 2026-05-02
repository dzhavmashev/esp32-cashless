// Function : FUN_40125ffc
// Address  : 0x40125ffc
// Size     : 30 bytes


void FUN_40125ffc(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_40185088(param_1,2);
  puVar1[1] = (char)((uint)param_2 >> 8);
  *puVar1 = (char)param_2;
  memw();
  memw();
  return;
}

