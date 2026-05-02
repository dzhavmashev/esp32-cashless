// Function : FUN_40124380
// Address  : 0x40124380
// Size     : 151 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40124380(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 auStack_3a [6];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = param_2;
  if ((*(byte *)(param_1 + 0x67) & 0x10) == 0) goto LAB_401243f2;
  iVar2 = *(int *)(param_1[1] + 0xf4);
  uStack_3c = (undefined1)iVar2;
  iVar2 = param_1[1] + (iVar2 + 9) * 0x10;
  uStack_3b = 0;
  memw();
  memw();
  (*(code *)&SUB_4008b530)(auStack_3a,0);
  uStack_34 = *(undefined4 *)(iVar2 + 4);
  uStack_30 = *(undefined4 *)(iVar2 + 8);
  uStack_2c = *(undefined4 *)(iVar2 + 0xc);
  uStack_28 = *(undefined4 *)(iVar2 + 0x10);
  if (*(int *)(*param_1 + 0x48) != 0) goto LAB_40124408;
  do {
    memw();
    iVar2 = FUN_40125ca4(param_2,0xfac09,&uStack_3c,0x18,0);
LAB_401243f2:
    do {
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return iVar2;
      }
      (*(code *)&SUB_40082ec4)();
LAB_40124408:
      iVar1 = FUN_40102858(&uStack_34,0x10);
      iVar2 = param_2;
    } while (iVar1 < 0);
  } while( true );
}

