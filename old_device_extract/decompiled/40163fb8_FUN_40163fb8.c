// Function : FUN_40163fb8
// Address  : 0x40163fb8
// Size     : 151 bytes


/* WARNING: Instruction at (ram,0x40164049) overlaps instruction at (ram,0x40164048)
    */
/* WARNING: Control flow encountered bad instruction data */

void FUN_40163fb8(int param_1,byte param_2,char param_3,uint param_4)

{
  undefined2 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 in_DBREAKC0;
  
  *(byte *)(param_1 + 0x82) = param_2;
  memw();
  param_4 = param_4 & 0xff;
  if (1 < param_2) {
    if (param_2 < 4) {
      uVar1 = 0x3fff;
      if ((param_3 != '\x01') &&
         ((param_3 == '\0' ||
          ((uVar1 = 0x7fff, param_3 != '\x02' && (uVar1 = 0xffff, param_3 != '\x03')))))) {
        uVar1 = 0x1fff;
      }
      *(undefined2 *)(param_1 + 0x78) = uVar1;
      memw();
      if (param_4 < 8) {
        UNRECOVERED_JUMPTABLE = *(code **)(&DAT_3f4246b0 + param_4 * 4);
        memw();
switchD_40164048_caseD_1:
                    /* WARNING: Jumptable at 0x4016400c did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
        return;
      }
      uVar1 = 0x94;
    }
    else {
      if (5 < param_2) {
        memw();
        return;
      }
      uVar1 = 0x3fff;
      if ((param_3 != '\x01') &&
         ((param_3 == '\0' ||
          ((uVar1 = 0x7fff, param_3 != '\x02' && (uVar1 = 0xffff, param_3 != '\x03')))))) {
        uVar1 = 0x1fff;
      }
      *(undefined2 *)(param_1 + 0x78) = uVar1;
      memw();
      if (param_4 < 8) {
        UNRECOVERED_JUMPTABLE = (code *)(&switchD_40164048::switchdataD_3f4246d0)[param_4];
        memw();
        switch(param_4) {
        case 0:
        case 7:
          uVar1 = 0x14;
          break;
        case 1:
          goto switchD_40164048_caseD_1;
        default:
          FUN_40184c44();
          rsr(in_DBREAKC0);
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
      else {
        uVar1 = 300;
      }
    }
    *(undefined2 *)(param_1 + 0x7e) = uVar1;
    memw();
  }
  memw();
  return;
}

