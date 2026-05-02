// Function : FUN_40151060
// Address  : 0x40151060
// Size     : 176 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ** FUN_40151060(uint param_1,ushort *param_2)

{
  int unaff_retaddr;
  undefined4 uVar1;
  undefined **ppuVar2;
  int iVar3;
  code *pcVar4;
  int unaff_a8;
  ushort uStack_2c;
  char cStack_2a;
  char cStack_29;
  
  cStack_2a = DAT_3ffc8a05;
  ppuVar2 = (undefined **)0x0;
  if (DAT_3ffc8a05 == '\0') {
    pcVar4 = (code *)((param_1 & 0xff) * 0x34 + _DAT_3ffc7a5c);
    uStack_2c = 0;
    cStack_29 = DAT_3ffc8a05;
    memw();
    if ((byte)pcVar4[0x21] < 8) {
      ppuVar2 = &switchD_401510a7::switchdataD_3f423d9c + (byte)pcVar4[0x21];
switchD_401510a7_caseD_401510a2:
      ppuVar2 = (undefined **)*ppuVar2;
      memw();
      switch(ppuVar2) {
      case (undefined **)0x40150f45:
        cStack_29 = cStack_2a;
        uVar1 = (*pcVar4)();
        ppuVar2 = (undefined **)FUN_40150fd5(ppuVar2,uVar1);
        return ppuVar2;
      case (undefined **)0x40150f7d:
        cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (undefined **)0x401510a2:
        goto switchD_401510a7_caseD_401510a2;
      case (undefined **)0x401510ee:
        *(int *)(unaff_retaddr + 0x30) = unaff_a8;
        memw();
        break;
      case (undefined **)0x4015112c:
        cust0();
        iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x128))
                          (*(undefined4 *)(_DAT_3ffbfc54 + 0x494),pcVar4,&uStack_2c);
        if (((iVar3 != 0) || ((int)(uint)uStack_2c < *(int *)(pcVar4 + 0x24))) ||
           ((uint)*(ushort *)(pcVar4 + 0x28) < (uint)uStack_2c)) {
          uStack_2c = (ushort)*(undefined4 *)(pcVar4 + 0x2c);
          memw();
        }
        unaff_a8 = (uint)*param_2 - (uint)uStack_2c;
        break;
      case (undefined **)0x401511da:
        (**(code **)(param_2 + 0x58))();
        return ppuVar2;
      }
      memw();
      return (undefined **)(uint)(unaff_a8 != 0);
    }
    ppuVar2 = (undefined **)0x1;
  }
  return ppuVar2;
}

