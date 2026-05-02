// Function : FUN_40123270
// Address  : 0x40123270
// Size     : 49 bytes


undefined4 FUN_40123270(int param_1,int *param_2)

{
  if ((param_1 == 0) && (param_2 != (int *)0x0)) {
    (*(code *)&SUB_40094c54)("ump/src/core_dump_checksum.c",0x71,"hecksum","cksum.c");
  }
  if (param_2 != (int *)0x0) {
    *param_2 = param_1;
  }
  memw();
  return 4;
}

