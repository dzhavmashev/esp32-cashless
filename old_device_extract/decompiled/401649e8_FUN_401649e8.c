// Function : FUN_401649e8
// Address  : 0x401649e8
// Size     : 68 bytes


/* WARNING: Instruction at (ram,0x40164a17) overlaps instruction at (ram,0x40164a16)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_401649e8(code *param_1,undefined **param_2)

{
  code *pcVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int unaff_a10;
  byte bStack_4;
  
  uVar6 = (byte)param_1[0xd] - 0x13 & 0xff;
  if (0xc < uVar6) {
    return (code *)0x72;
  }
switchD_40164a01_switchD:
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(uVar6) {
  case 0:
    if (param_2 <= &switchD_40164a01::switchdataD_3f424794) {
      uVar6 = ((int)(&switchD_40164a01::switchdataD_3f424794)[uVar6] >> 1) * 3 & 0xff;
      return (code *)((uVar6 < 0x20) * uVar6 + (uint)(uVar6 >= 0x20) * 0x20);
    }
    return param_1;
  case 1:
                    /* WARNING: Could not recover jumptable at 0x40164871. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (code *)(**(code **)(param_1 + (int)param_2 * 4))
                               (*(code **)(param_1 + (int)param_2 * 4));
    return pcVar1;
  case 2:
    cust0();
    pcVar1 = (code *)(uint)bStack_4;
    pcVar2 = pcVar1 + 0x1d;
    (*pcVar1)(0xa3aa8033);
    pcVar1 = pcVar1 + (int)pcVar2 * 4;
    cust0();
    uVar6 = (uint)bRam03f9251e;
    if (uVar6 == ((uint)param_2 & 0xff)) {
      uVar3 = FUN_401649e8(pcVar1);
      if ((byte)pcVar1[0x1e] + 0x14 < uVar3) {
        FUN_40186c44(pcVar1,3);
        pcVar1[0xe] = (code)0x3;
        memw();
        *(uint *)(pcVar1 + 0x60) = (uVar6 - 1 & 0xff) * 0xc + *(int *)(pcVar1 + 0x70);
        memw();
        FUN_401641bc(pcVar1);
        iVar5 = 0;
        do {
          if (((uint)(byte)pcVar1[0x10] & 1 << ((byte)iVar5 & 0x1f)) != 0) {
            FUN_40164658(pcVar1,3,iVar5);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 8);
        return pcVar1;
      }
    }
    else {
      pcVar1[0xc] = (code)0x0;
      memw();
      if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
        memw();
        iVar5 = _DAT_3ff73c00 + _DAT_3ffc1a30;
      }
      else {
        memw();
        iVar5 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
      }
      *(int *)(pcVar1 + 0x50) = iVar5;
      pcVar1[0xd] = *(code *)((((uint)param_2 & 0xff) + 1 & 0xff) * 0xc + *(int *)(pcVar1 + 0x70));
      memw();
      memw();
      uVar4 = FUN_40163f8c();
      FUN_40186c6c(pcVar1,uVar4);
    }
    FUN_401641ec(pcVar1);
    return pcVar1;
  case 3:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 4:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 5:
    FUN_40164858(param_1[1]);
    pcVar1 = (code *)switchD_40164a01::caseD_7(0x72);
    return pcVar1;
  case 6:
    goto switchD_40164a01_switchD;
  default:
    return param_1 + -unaff_a10;
  }
}

