// Function : FUN_4011c218
// Address  : 0x4011c218
// Size     : 40 bytes


undefined1 FUN_4011c218(uint *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  uint *apuStack_48 [2];
  undefined4 uStack_40;
  
  uVar1 = 0xf0;
  if ((param_1 != (uint *)0x0) && ((*param_1 & 0xf0) == 0x10)) {
    memw();
    apuStack_48[0] = param_1;
    uStack_40 = param_2;
    uVar1 = FUN_4011bff4(&DAT_4011d64c,apuStack_48);
  }
  return uVar1;
}

