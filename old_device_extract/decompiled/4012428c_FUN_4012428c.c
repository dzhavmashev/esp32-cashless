// Function : FUN_4012428c
// Address  : 0x4012428c
// Size     : 155 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4012428c(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_3c [24];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar3 = -1;
  if (0x62 < param_4) {
    iVar4 = param_3 + 0x51;
    bVar1 = *(byte *)(param_3 + 6);
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_3c,iVar4,0x10);
    (*(code *)&SUB_4008b530)(iVar4,0,0x10);
    memw();
    iVar2 = FUN_40106090(param_2,*(undefined4 *)(param_2 + 0x58),param_1,bVar1 & 7,param_3,param_4,
                         iVar4);
    iVar3 = -1;
    if (iVar2 == 0) {
      iVar3 = (*(code *)&SUB_4008b33c)(auStack_3c,iVar4,0x10);
      iVar3 = -(uint)(iVar3 != 0);
    }
    (*(code *)&SUB_4008b3d0)(iVar4,auStack_3c,0x10);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar3;
}

