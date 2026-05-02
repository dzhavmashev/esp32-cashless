// Function : FUN_400ec5fc
// Address  : 0x400ec5fc
// Size     : 41 bytes


undefined4 FUN_400ec5fc(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((0x7f < param_1) && (uVar1 = 2, 0x3fff < param_1)) && (uVar1 = 3, 0x1fffff < param_1)) &&
     (uVar1 = 4, 0xfffffff < param_1)) {
    uVar1 = 0;
  }
  return uVar1;
}

