// Function : FUN_400ed7f4
// Address  : 0x400ed7f4
// Size     : 281 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ed7f4(char *param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined8 uVar6;
  undefined1 auStack_34 [16];
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  if (*param_1 != '\0') {
    param_1 = (char *)0x0;
    goto LAB_400ed873;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    param_1 = (char *)0x0;
    goto LAB_400ed873;
  }
  if (*(int *)(param_1 + 0x10) == *(int *)(param_1 + 0x24)) goto LAB_400ed88e;
  if (param_2 != 0) goto LAB_400ed891;
  uVar6 = func_0x40085c04();
  uVar1 = FUN_401847ec("Aborted");
  uVar2 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
  FUN_4012105c("ailed\r\n",uVar2,uVar1,0x122,"u/%u\n\r\n",*param_1,*(undefined4 *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x10));
  FUN_400ed41c(param_1);
  cVar5 = '\f';
LAB_400ed870:
  *param_1 = cVar5;
  param_1 = (char *)0x0;
LAB_400ed873:
  do {
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
LAB_400ed88e:
    if (param_2 != 0) {
LAB_400ed891:
      if (*(int *)(param_1 + 0xc) != 0) {
        FUN_400ed674(param_1);
      }
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x24);
    }
    FUN_400f0620(param_1 + 0x44);
    if ((param_1[0x43] & 0x80U) == 0) {
      if (*(int *)(param_1 + 0x34) != 0) {
        uVar4 = *(uint *)(param_1 + 0x3c);
        goto LAB_400ed8b8;
      }
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x40) >> 0x18 & 0x7f;
LAB_400ed8b8:
      if (uVar4 != 0) {
        FUN_400f0650(auStack_34,param_1 + 0x44);
        iVar3 = FUN_400f1190(param_1 + 0x34,auStack_34);
        FUN_400f0a50(auStack_34);
        if (iVar3 == 0) break;
      }
    }
    param_1 = (char *)FUN_400ed5e8(param_1);
  } while( true );
  FUN_400ed41c(param_1);
  cVar5 = '\a';
  goto LAB_400ed870;
}

