// Function : FUN_4018e294
// Address  : 0x4018e294
// Size     : 79 bytes


undefined4 * FUN_4018e294(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)&SUB_40094c54)("ts/heap/multi_heap.c",0x6f,"oc_impl","0x%08x\n");
  }
  if (0x13 < param_2) {
    iVar2 = param_2 - 0x14;
    iVar1 = FUN_4018e270(param_1 + 5,iVar2,0);
    param_1[4] = iVar1;
    if (iVar1 != 0) {
      *param_1 = 0;
      memw();
      iVar1 = (*(code *)&SUB_400947a8)();
      param_1[1] = iVar2 - iVar1;
      param_1[3] = iVar2;
      param_1[2] = iVar2 - iVar1;
      memw();
      return param_1;
    }
  }
  return (undefined4 *)0x0;
}

