// Function : FUN_400dc468
// Address  : 0x400dc468
// Size     : 234 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dc468(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  *(undefined1 *)(param_1 + 0x30) = 1;
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  *(int *)(param_1 + 0x38) = param_2;
  *(undefined4 *)(param_1 + 0x78) = 0;
  FUN_400dc43c(param_1);
  FUN_400f0be8(auStack_34,"rved[i].start");
  FUN_400dc0a0(param_1,auStack_34);
  FUN_400f0a50(auStack_34);
  if (*(int *)(param_1 + 0x54) == 0) goto LAB_400dc4f4;
  if (*(char *)(*(int *)(param_1 + 0x54) + 5) == '\0') goto LAB_400dc4f4;
  *(undefined1 *)(param_1 + 0x70) = 1;
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x74) = uVar1;
  FUN_400f06a4(0x3ffc5490,"ng %us\n",param_2);
  param_3 = (int *)0x1;
  while( true ) {
    param_2 = iStack_24;
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400dc4f4:
    *(undefined1 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    func_0x4009246c(*(undefined4 *)(param_1 + 0x48),4,(uint)(param_2 * 1000000) / 1000,0,0);
    uVar1 = *(undefined4 *)(param_1 + 0x48);
    uVar2 = func_0x40090b58();
    func_0x4009246c(uVar1,1,uVar2,0,0);
    piVar3 = param_3;
    if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
      piVar3 = (int *)*param_3;
    }
    FUN_400f06a4(0x3ffc5490,"g ACK)\n",param_2,piVar3);
  }
  return;
}

