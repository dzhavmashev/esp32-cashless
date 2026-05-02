// Function : FUN_4011c57c
// Address  : 0x4011c57c
// Size     : 34 bytes


undefined1 FUN_4011c57c(uint *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  
  uVar1 = 0xf0;
  if ((param_1 != (uint *)0x0) && ((*param_1 & 0xf0) == 0x10)) {
    uVar1 = FUN_4011c4cc(param_1,param_2,param_3);
  }
  return uVar1;
}

