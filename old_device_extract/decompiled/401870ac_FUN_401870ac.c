// Function : FUN_401870ac
// Address  : 0x401870ac
// Size     : 24 bytes


undefined4 FUN_401870ac(int *param_1,undefined1 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_24 [36];
  
  auStack_24[0] = param_2;
  uVar1 = (**(code **)(*param_1 + 0xc))(param_1,auStack_24,1);
  return uVar1;
}

