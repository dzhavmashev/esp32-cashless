// Function : FUN_4011c4cc
// Address  : 0x4011c4cc
// Size     : 170 bytes


char FUN_4011c4cc(uint *param_1,int *param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint *apuStack_48 [2];
  uint uStack_40;
  
  cVar2 = -0xb;
  if ((param_1[4] == 0) || (bVar1 = (byte)param_1[0xd], (bVar1 & 8) != 0)) goto LAB_4011c565;
  if ((char)bVar1 < '\0') {
    *(byte *)(param_1 + 0xd) = bVar1 & 0x7f;
    memw();
  }
  else {
    cVar2 = FUN_4011c374(param_1,param_2,param_3);
    if (cVar2 != '\0') goto LAB_4011c565;
    iVar3 = *param_2;
    if ((param_3 & 8) == 0) {
      uVar4 = 1;
      if (iVar3 != 0) {
        uVar4 = (uint)*(ushort *)(iVar3 + 8);
      }
      if ((*param_1 & 0xf0) == 0x10) {
        memw();
        apuStack_48[0] = param_1;
        uStack_40 = uVar4;
        FUN_4011bff4(&DAT_4011d64c,apuStack_48);
      }
    }
    if (iVar3 != 0) goto LAB_4011c565;
    if ((param_3 & 0x10) != 0) {
      *(byte *)(param_1 + 0xd) = (byte)param_1[0xd] | 0x80;
      memw();
      cVar2 = -7;
      goto LAB_4011c565;
    }
  }
  if ((code *)param_1[0xf] != (code *)0x0) {
    memw();
    (*(code *)param_1[0xf])(param_1,1,0);
  }
  if (param_1[2] == 0) {
    cVar2 = FUN_4011c350(param_1);
    if (cVar2 == '\0') {
      cVar2 = -0xe;
    }
  }
  else {
    FUN_4011c014(param_1,1);
    cVar2 = -0xf;
  }
LAB_4011c565:
  memw();
  return cVar2;
}

