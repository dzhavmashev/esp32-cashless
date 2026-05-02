// Function : FUN_40121a90
// Address  : 0x40121a90
// Size     : 98 bytes


int FUN_40121a90(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    (*(code *)&SUB_40094c54)("ump/src/core_dump_common.c",0x10c,"ommon.c","");
  }
  if (param_1 == 1) {
    puVar2 = (undefined1 *)0x400965d8;
    puVar1 = (undefined1 *)0x400965d8;
    *param_2 = 0x400965d8;
    memw();
  }
  else if (param_1 == 0) {
    puVar2 = &DAT_3ffc1bc0;
    puVar1 = &DAT_3ffc1bc0;
    *param_2 = &DAT_3ffc1bc0;
  }
  else if (param_1 == 2) {
    puVar2 = &DAT_50000200;
    puVar1 = &DAT_50000200;
    *param_2 = &DAT_50000200;
    memw();
  }
  else {
    if (param_1 != 3) {
      return -1;
    }
    puVar2 = (undefined1 *)0x3ff80000;
    puVar1 = (undefined1 *)0x3ff80000;
    *param_2 = 0x3ff80000;
    memw();
  }
  memw();
  return (int)puVar1 - (int)puVar2;
}

