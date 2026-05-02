// Function : FUN_40169e80
// Address  : 0x40169e80
// Size     : 22 bytes


undefined2 FUN_40169e80(uint param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0x20;
  if ((param_1 & 0xffff) < 3) {
    uVar1 = *(undefined2 *)((param_1 & 0xffff) * 2 + 0x3ffc3898);
  }
  return uVar1;
}

