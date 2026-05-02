// Function : FUN_400da79c
// Address  : 0x400da79c
// Size     : 321 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da79c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined1 *param_5,
                 undefined1 *param_6,undefined1 *param_7)

{
  undefined4 extraout_a3;
  int iVar1;
  undefined4 ****ppppuVar2;
  int iVar3;
  undefined4 ***local_44 [3];
  byte bStack_35;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_7 != param_5) goto LAB_400da825;
  FUN_400f0be8(local_44,param_3);
  FUN_400f0c04(auStack_34,param_4,param_5);
  ppppuVar2 = local_44;
  if ((bStack_35 & 0x80) == 0) {
    ppppuVar2 = (undefined4 ****)local_44[0];
  }
  FUN_400f06a4(0x3ffc5490,"econds\n",ppppuVar2,param_5);
  if (*(int *)(param_1 + 0x818) != 0) {
    FUN_400da780(param_1 + 0x810,local_44,auStack_34);
  }
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(local_44);
  while( true ) {
    param_1 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    param_7 = &DAT_3ffc5708;
    param_3 = extraout_a3;
LAB_400da825:
    if (param_6 == (undefined1 *)0x0) {
      FUN_400f0be8(auStack_34,param_3);
      FUN_400f0d60(param_1 + 0x84c,auStack_34);
      FUN_400f0a50(auStack_34);
      FUN_400f0d70(param_1 + 0x83c,&DAT_3f42161d);
      FUN_400f0b60(param_1 + 0x83c,param_7);
      *(undefined1 **)(param_1 + 0x85c) = param_7;
    }
    iVar1 = param_1 + 0x83c;
    param_6 = param_5 + (int)param_6;
    FUN_400f0f40(iVar1,param_4,param_5);
    if (param_7 <= param_6) {
      param_4 = param_1 + 0x84c;
      iVar3 = param_4;
      if ((*(byte *)(param_1 + 0x85b) & 0x80) == 0) {
        iVar3 = *(int *)(param_1 + 0x84c);
      }
      FUN_400f06a4(0x3ffc5490,"bytes)\n",iVar3,*(undefined4 *)(param_1 + 0x85c));
      param_5 = *(undefined1 **)(param_1 + 0x818);
      if (param_5 != (undefined1 *)0x0) {
        FUN_400da780(param_1 + 0x810,param_4,iVar1);
      }
      FUN_400f0d70(iVar1,&DAT_3f42161d);
      FUN_400f0d70(param_4,&DAT_3f42161d);
      *(undefined4 *)(param_1 + 0x85c) = 0;
    }
  }
  return;
}

