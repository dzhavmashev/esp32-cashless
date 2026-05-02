// Function : FUN_400efe2c
// Address  : 0x400efe2c
// Size     : 60 bytes


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x400ef865) overlaps instruction at (ram,0x400ef864)
    */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x400ef8a3) */
/* WARNING: Removing unreachable block (ram,0x400ef6d6) */
/* WARNING: Removing unreachable block (ram,0x400ef6dc) */
/* WARNING: Removing unreachable block (ram,0x400ef6ea) */
/* WARNING: Removing unreachable block (ram,0x400ef700) */
/* WARNING: Removing unreachable block (ram,0x400ef703) */
/* WARNING: Removing unreachable block (ram,0x400ef706) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400efe2c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint in_a13;
  
  iVar4 = func_0x40082eac();
  cust0();
  if (param_2 != 0) {
    if (in_a13 < 2) {
      cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar5 = 0x13e2e54c;
    do {
      FUN_400f0a50(uVar5);
      thunk_FUN_401710d8(param_1);
      uVar5 = 0x13e2e55c;
    } while( true );
  }
  iVar1 = 0x5a;
  do {
    uVar2 = 0;
    if (-1 < iVar4) {
      FUN_400f0be8(0x638b0578,"ction: ");
      uVar2 = FUN_400f143c(0x638b0558,0x638b0578);
      uVar2 = uVar2 >> 0x1f;
      FUN_400f0a50(0x638b0578);
    }
    FUN_400f0a50(0x638b0568);
    if (uVar2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      cRam000000f6 = '\0';
    }
    do {
      do {
        FUN_400f0be8(0x638b0578,"-Length");
        iVar4 = FUN_400f122c(0x638b0548,0x638b0578);
        FUN_400f0a50(0x638b0578);
        if (iVar4 != 0) {
          FUN_400f0d18(0x638b0518,0x638b0558);
        }
        FUN_400f0be8(0x638b0578,"ncoding");
        iVar4 = FUN_400f122c(0x638b0548,0x638b0578);
        FUN_400f0a50(0x638b0578);
        if (iVar4 != 0) {
          FUN_400f0d18(param_5,0x638b0558);
        }
        FUN_400f0be8(0x638b0578,"ocation");
        iVar4 = FUN_400f122c(0x638b0548,0x638b0578);
        FUN_400f0a50(0x638b0578);
        if (iVar4 != 0) {
          FUN_400f0d4c(0x638b0568,0x638b0528);
          FUN_400f0d4c(0x638b0578,0x638b0558);
          FUN_400eeef0(0x5a,0x638b0568,0x638b0578);
          FUN_400f0a50(0x638b0578);
          FUN_400f0a50(0x638b0568);
        }
        for (uVar2 = 0; uVar2 < uRam000000ea; uVar2 = uVar2 + 1) {
          iVar4 = FUN_400f122c(iRam000000e6 + uVar2 * 0x20,0x638b0548);
          if (iVar4 != 0) {
            FUN_400f0d18(iRam000000e6 + uVar2 * 0x20 + 0x10,0x638b0558);
            break;
          }
        }
        FUN_400f0a50(0x638b0558);
        FUN_400f0a50(0x638b0548);
        do {
          iVar4 = FUN_400f11c0(0x638b0538,param_3);
          if (iVar4 != 0) {
            iVar4 = (*(code *)&LAB_40183a7b_1)(0x638b0518);
            if (iVar4 == 0) goto LAB_400efa6d;
            FUN_400f0be8(0x638b0578,"-Cookie");
            iVar4 = FUN_400f122c(0x638b0518,0x638b0578);
            FUN_400f0a50(0x638b0578);
            if (iVar4 == 0) goto LAB_400efa44;
            uVar5 = 1;
            goto LAB_400efa01;
          }
          FUN_400f0a50(0x638b0538);
          while( true ) {
            iVar4 = (*(code *)&LAB_40184637_1)(0x5a);
            if (iVar4 == 0) {
              iVar1 = -5;
              goto LAB_400efa15;
            }
            iVar4 = (**(code **)(*piRam00000062 + 0x18))();
            if (iVar4 != 0) break;
            iVar4 = FUN_400f1a9c();
            if ((uint)uRam00000080 < (uint)(iVar4 - param_6)) {
              iVar1 = -0xb;
LAB_400efa15:
              while( true ) {
                FUN_400f0a50(0x638b0528);
                FUN_400f0a50(0x638b0518);
                memw();
                memw();
                if (iRam638b0588 == _DAT_3ffc5708) break;
                func_0x40082ecc();
LAB_400efa44:
                FUN_400f0be8(0x638b0578,"chunked");
                iVar3 = FUN_400f122c(0x638b0518,0x638b0578);
                FUN_400f0a50(0x638b0578);
                iVar4 = -9;
                if (iVar3 != 0) {
LAB_400efa6d:
                  uVar5 = 0;
LAB_400efa01:
                  *(undefined4 *)(iVar1 + 0xb8) = uVar5;
                  iVar4 = *(int *)(iVar1 + 0x94);
                  if (*(int *)(iVar1 + 0x94) == 0) {
                    iVar4 = -7;
                  }
                }
                iVar1 = iVar4;
                FUN_400f0a50(0x638b0538);
              }
              return;
            }
            FUN_400f1ab4(10);
          }
          FUN_400f08c0(0x638b0538,piRam00000062,10);
          FUN_400f17d0(0x638b0538);
          param_6 = FUN_400f1a9c();
          iVar4 = FUN_400f13f0(0x638b0538,0x3a);
        } while (iVar4 == 0);
        uVar5 = FUN_400f13f0(0x638b0538,0x3a);
        FUN_400f1520(0x638b0548,0x638b0538,0,uVar5);
        iVar4 = FUN_400f13f0(0x638b0538,0x3a);
        FUN_400ed9cc(0x638b0558,0x638b0538,iVar4 + 1);
        FUN_400f17d0(0x638b0558);
        FUN_400f0be8(0x638b0578,"");
        iVar4 = FUN_400f122c(0x638b0548,0x638b0578);
        FUN_400f0a50(0x638b0578);
        if (iVar4 != 0) {
          FUN_400f0d18(0x638b0528,0x638b0558);
        }
        FUN_400f0be8(0x638b0578,"re");
        iVar4 = FUN_400f122c(0x638b0548,0x638b0578);
        FUN_400f0a50(0x638b0578);
        if (iVar4 != 0) {
          uRam000000f2 = FUN_400f1854(0x638b0558);
        }
      } while (cRam000000f6 == '\0');
      FUN_400f0be8(0x638b0578,"tocol\r\n");
      iVar4 = FUN_400f122c(0x638b0548,0x638b0578);
      FUN_400f0a50(0x638b0578);
    } while (iVar4 == 0);
    FUN_400f0be8(0x638b0568,"p-alive");
    iVar4 = FUN_400f143c(0x638b0558,0x638b0568);
  } while( true );
}

