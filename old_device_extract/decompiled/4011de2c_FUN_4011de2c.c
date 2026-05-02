// Function : FUN_4011de2c
// Address  : 0x4011de2c
// Size     : 46 bytes


void FUN_4011de2c(int param_1)

{
  undefined4 uVar1;
  
  if (0x400000 < (uint)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc))) {
    (*(code *)&SUB_40094c54)("ts/heap/heap_caps_init.c",0x21,"ps_init","_malloc");
  }
  uVar1 = FUN_4018e394();
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  memw();
  return;
}

