// Function : FUN_4011c4a8
// Address  : 0x4011c4a8
// Size     : 34 bytes


undefined1 FUN_4011c4a8(uint *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  
  uVar1 = 0xf0;
  if ((param_1 != (uint *)0x0) && ((*param_1 & 0xf0) != 0x10)) {
    uVar1 = FUN_4011c374(param_1,param_2,param_3);
  }
  return uVar1;
}

